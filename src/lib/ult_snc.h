const int trigPin = 11;
const int echoPin = 12;
double duration = 0;
double distance = 0;

void set_ult_snc(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}