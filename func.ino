void func(){
  // float alpha, omiga; //state two floating-point variables, alpha and omiga
//if MPU6050 DMP status to error, the program stop working
if (!dmpReady)
return;
// wait for MPU interrupt or extra packet(s) available
if (!mpuInterrupt && fifoCount < packetSize)
return;
// reset interrupt flag and get INT_STATUS byte
mpuInterrupt = false;
mpuIntStatus = mpu.getIntStatus();
// check for overflow (this should never happen unless our code is too inefficient)
if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
// reset so we can continue cleanly
mpu.resetFIFO();
Serial.println("FIFO overflow!");
}
// otherwise, check for DMP data ready interrupt (this should happen frequently) }
else if (mpuIntStatus & 0x02) {
// wait for correct available data length, should be a VERY short wait
while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
// read a packet from FIFO
mpu.getFIFOBytes(fifoBuffer, packetSize);
// track FIFO count here in case there is > 1 packet available
// (this lets us immediately read more without waiting for an interrupt)
fifoCount -= packetSize;
mpu.dmpGetQuaternion(&q, fifoBuffer);
mpu.dmpGetGravity(&gravity, &q);
mpu.dmpGetYawPitchRoll(ypr, &q, &gravity); //take three axis angle from the DMP. they are Yaw, Pitch and Roll. put them into the succession of the array.Units: radian
alpha=-ypr[2] * 180/M_PI;
omiga=mpu.getRotationX()/16.4; //configuration is 16. plus or minus2000°/s, 65536/4000
// get current FIFO count fifoCount = mpu.getFIFOCount();
Serial.print("Alpha "); Serial.print(alpha); Serial.print("\tOmiga "); Serial.println(omiga);
}
}
