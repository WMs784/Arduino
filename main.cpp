#include "std.h"
#define rep(i,n) for(int i = 0;i < (int)n;i++)

using namespace std;


void setup() {
  setup_sensors();
  Serial.begin(9600);
}
void loop() {
   digitalWrite(GREEN, HIGH);
   Serial.println("start");
   delay(1000);
   rep(i,180/15){
     set_map(dis(),15*i);
   }
   digitalWrite(GREEN, LOW);
   delay(1000);
   digitalWrite(BLUE, HIGH);
   delay(1000);
   int time = millis();
   Serial.println(time);
   scan();
   Serial.println(time);
   delay(1000);
   Serial.println(time);
   cout << time << endl;
}
