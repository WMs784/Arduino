#include "std.h"
#define rep(i,n) for(int i = 0;i < (int)n;i++)

int itv = 15;

void setup() {
  setup_sensors();
}
void loop() {
    digitalWrite(RED, HIGH);
    delay(1000);
    rep(i,180/itv){
        myservo.write(itv*i);
        set_map(dis(),itv*i);
    }
    degitalWrite(RED,LOW);
}
