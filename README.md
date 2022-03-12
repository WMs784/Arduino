# Arduino 先遣ローバー

## 環境
- AVR Boards 1.8.2 ← ArduinoSTLを使うためにダウングレード（デフォルトは1.8.3）
- Arduino Uno, Arduino IDE 1.8.19, 書き込み先 "/dev/tty.usbmodem14101"
### 使用ライブラリ
- ArduinoSTL.h
- I2Cdev
- MPU6050

## Note
- 経路探索はグリッドグラフにおける幅優先探索により行う(無向グラフは用いない)．
- なるべく曲がる回数が少なくなるようにというのも考慮したほうが良い．曲がった後の距離を短く
- ローバの方向転換時のモータ制御は磁気センサからのデータに従う．→ 応答性の問題から特別な制御が必要かも：時間で考えた方が良い
- 進む距離はロータリーエンコーダの値を参照しながら前進．


## Task
- mapは確率変数で管理すると精度上がりそう
- 統計的な誤差のキャリブレーション

## Memo
- 角位置センサの設定読み込みにすごく時間がかかっている
→ おそらくコードどっか間違ってるかも．要確認！

## sample code by michi
```total1.ino
// LED
const int RED = A0;
const int BLUE = A1;
const int GREEN = A2;
// DCモータ
const int motor11 = 3;
const int motor12 = 4;
const int motor21 = 5;
const int motor22 = 6;
// サーボモータ
#include <Servo.h>
Servo myservo;
const int SV_PIN = 9;
// ロータリーエンコーダ
const int pinA = 7;
const int pinB = 8;
int encoderPosCount = 0;
int pinALast;
int aVal;
boolean bCW;
// 超音波センサ
const int trigPin = 11;
const int echoPin = 12;
double duration = 0;
double distance = 0;
//　水位センサ
const int sensorPin = A3; //sensor pin connected to analog pin A0
int liquid_level;
void setup()
{
  Serial.begin(9600);
  // LED
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  //モータ
  pinMode(motor11, OUTPUT);
  pinMode(motor12, OUTPUT);
  pinMode(motor21, OUTPUT);
  pinMode(motor22, OUTPUT);
  //サーボ
  myservo.attach(SV_PIN, 500, 2400);  // サーボの割当(パルス幅500~2400msに指定)
  //ロータリエンコーダ
  pinMode (pinA, INPUT);
  pinMode (pinB, INPUT);
  pinALast = digitalRead(pinA);
  //超音センサ
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //水位センサ
  pinMode(sensorPin, INPUT);
}
void loop() {
  //LEDをセンシング中の緑に
  digitalWrite(GREEN, HIGH);
  //超音波距離センサとサーボ
  for ( int i = 0; i < 6; i++) {
    for ( int j = 0; j < 100; j++) {
      digitalWrite(trigPin, LOW);
      digitalWrite(echoPin, LOW);
      delayMicroseconds(1);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance += duration * 0.000001 * 34000 / 2;
    }
    digitalWrite(trigPin, LOW);
    digitalWrite(echoPin, LOW);
    distance = distance * 0.01;//１００個の平均を取る
    Serial.print("distance ");
    Serial.print(distance);
    Serial.print("angle ");
    Serial.println(i * 30);
    myservo.write(i * 30);  // サーボモーターを30i度の位置まで動かす
    delay(2000);
  }
  //LEDを移動中の青に
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  //移動開始
  digitalWrite(motor12, LOW);
  digitalWrite(motor11, HIGH);
  //エンコーダの値読み取り、モータの動きは適当
  int encoderPosCount = 0;
  while (encoderPosCount < 10) {
    aVal = digitalRead(pinA);
    if (aVal != pinALast) {
      if (digitalRead(pinB) != aVal) {
        encoderPosCount ++;
      }
      else {
        encoderPosCount--;
      }
      Serial.print("Encoder Position: ");
      Serial.println(encoderPosCount);
    }
    pinALast = aVal;
  }
  digitalWrite(motor12, HIGH);
  digitalWrite(motor11, LOW);
  delay(5000);
  digitalWrite(motor12, LOW);
  digitalWrite(motor11, LOW);
  digitalWrite(motor21, HIGH);
  digitalWrite(motor22, LOW);
  while ((encoderPosCount < 20) && (encoderPosCount >= 10)) {
    aVal = digitalRead(pinA);
    if (aVal != pinALast) {
      if (digitalRead(pinB) != aVal) {
        encoderPosCount ++;
      }
      else {
        encoderPosCount--;
      }
      Serial.print("Encoder Position: ");
      Serial.println(encoderPosCount);
    }
    pinALast = aVal;
  }
  digitalWrite(motor22, HIGH);
  digitalWrite(motor21, LOW);
  delay(5000);
  digitalWrite(motor21, LOW);
  digitalWrite(motor22, LOW);
  digitalWrite(BLUE, LOW);
}
```