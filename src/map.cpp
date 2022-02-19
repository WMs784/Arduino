#include <bits/stdc++.h>
#include "sensors.h"
#define rep(i,n) for (int i = 0;i < (int)n;i++)

using namespace std;

int length = 400,width = 200;
vector<vector<int>> field_map(length,vector<int>(width,0));

void set_map(){
    int theta = 20; //暫定的な偏角
    rep(i,6) {
        rep(j,100) {
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
    }
    int x = distance*cos(theta), y = distance*sin(theta);
    rep(i,length){
        rep(j,width){
            if(i == x && j == y) field_map[i][j]--;
            else field_map[i][j]++;
        }
    }
}