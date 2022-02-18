#include <Servo.h>
Servo myservo;
const int SV_PIN = 9;

void set_svm(){
    myservo.attach(SV_PIN, 500, 2400);  // サーボの割当(パルス幅500~2400msに指定)
}