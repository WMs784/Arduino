#include "src/lib.h"
void setup() {
  set_led();
  set_svm();
}
void loop() {
  digitalWrite(RED, HIGH);
  myservo.write(30);  // サーボモーターを30度の位置まで動かす
  delay(2000);
}