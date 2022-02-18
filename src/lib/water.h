const int sensorPin = A3; //sensor pin connected to analog pin A0
int liquid_level;
void set_water(){
    pinMode(sensorPin, INPUT);
}