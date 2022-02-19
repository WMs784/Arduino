#include "std.h"
#include "src/sensors.h"
#include "src/map.h"
void setup() {
  setup_sensors();
}
void loop() {
  digitalWrite(RED, HIGH);
  // myservo.write(30);  // サーボモーターを30度の位置まで動かす
  set_map(dis(),ang());
  delay(2000);
}