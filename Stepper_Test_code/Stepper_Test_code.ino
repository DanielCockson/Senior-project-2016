//#incluee <AccelStepper.h>
#include <Wire.h> 
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMStop (0x60);
Adafruit_StepperMotor *myMotor = AFMStop.getStepper(200, 2);

void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
AFMStop.begin();
myMotor->setSpeed(200);

}

void loop() {
  // put your main code here, to run repeatedly:
myMotor->step(200, FORWARD, DOUBLE); //(two hundred steps, forward, ???)
delay(1000); //(milliseconds?)
myMotor->step(400, BACKWARD, DOUBLE);
}
