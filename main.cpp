#include "src/sensors.h"
void setup() {
  set_sensors();
}
void loop() {
  digitalWrite(RED, HIGH);
  myservo.write(30);  // サーボモーターを30度の位置まで動かす
  delay(2000);
}