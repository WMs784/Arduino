#ifndef _LED
#define _LED

void set_led();

#endif

const int RED = A0;
const int BLUE = A1;
const int GREEN = A2;

void set_led(){
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
}