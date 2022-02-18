#include "lib.h"
void setup() {
  set_led();
  set_svm();
}
int i = 0;
void loop() {
  digitalWrite(RED, HIGH);
  myservo.write(-30*i);  // サーボモーターを30度の位置まで動かす
//   i += 10;
  delay(2000);
}