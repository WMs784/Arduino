#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h" //instantiate a MPU6050 object, the object name is mpu MPU6050 mpu(0x68);
//statement MPU6050 control and state variable
bool dmpReady = false;
uint8_t mpuIntStatus;
uint16_t packetSize;
uint16_t fifoCount;
//set true if DMP init was successful
//This variable is used to save the state when MPU6050 stop
//Return to equipment status, 0 for success, others for error
// expected DMP packet size (default is 42 bytes)
// count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer //state direction and movement of variables:
Quaternion q;
VectorFloat gravity;
float ypr[3];
//statement MPU6050 control and state variable
uint8_t devStatus;
MPU6050 mpu(0x68);
volatile bool mpuInterrupt = false;
void dmpDataReady()
{
mpuInterrupt = true; }
void setup() {
// indicates whether MPU interrupt pin has
Serial.begin(9600); //Open the serial port and set the baud rate to 115200, upload the program to the Arduino IDE and observe th situation of the serial port
//add the bus sequence of I2C
Wire.begin();
//Initial setup MPU6050
Serial.println("Initializing I2C devices...");
mpu.initialize();
//verify connection
Serial.println("Testing device connections..."); Serial.println(mpu.testConnection() ?
"MPU6050 connection successful":
"MPU6050 connection failed");
delay(2);
//delay 2ms
//upload and configure DMP digital motion processing engine
Serial.println("Initializing DMP...");
devStatus = mpu.dmpInitialize(); //Return to DMP status, 0 for success, others for error
// if return to 0
if (devStatus == 0) {
// make DMP digital motion processing engine
Serial.println("Enabling DMP...");
mpu.setDMPEnabled(true);
//Enabling the Arduino interrupt detection
Serial.println("Enabling interrupt detection (Arduino external interrupt 0)..."); attachInterrupt(0, dmpDataReady, RISING);
mpuIntStatus = mpu.getIntStatus();
// set our DMP Ready flag so the main loop() function knows it's okay to use it
Serial.println("DMP ready! Waiting for first interrupt...");
dmpReady = true;
// get expected DMP packet size for later comparison
packetSize = mpu.dmpGetFIFOPacketSize(); }
else
{
// ERROR!
// 1 = initial memory load failed
// 2 = DMP configuration updates failed
// (if it's going to break, usually the code will be 1)
Serial.print("DMP Initialization failed (code ");
Serial.print(devStatus);
Serial.println(")");
}
}
void loop() {
  func();
}
