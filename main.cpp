#include "std.h"
#define rep(i,n) for(int i = 0;i < (int)n;i++)

int itv = 15;

void setup() {
  setup_sensors();
}
void loop() {
    digitalWrite(GREEN, HIGH);
    delay(1000);
    rep(i,180/itv){
      set_map(dis(),itv*i);
    }
    digitalWrite(GREEN, LOW);
    delay(1000);
    digitalWrite(BLUE, HIGH);
    delay(1000);
}
