// servo setup
#include <Servo.h>
Servo myservo;

// light sensor setup
#include "Arduino.h"
#include "SI114X.h"
#include <Wire.h>

SI114X SI1145 = SI114X();

//StepperMotor
#include <StepperMotor.h>
StepperMotor motor(8,9,10,11);

//variable
int servoPos;
int stepPos;
int highVisible = 0;
int i = 0;
int n = 0;

long previousMillis = 0;        // will store last time the servo was turnning
long interval = 50;           // interval at which to turn (milliseconds)
bool delaystate = false;      //state of the dalay

void setup() {

}
void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    // save the last time the servo turn
    previousMillis = currentMillis;
    if (delaystate = false) {
      delayState = true;
      motor.setStepDuration(1);
      SI1145.Begin();
      Serial.begin(9600);
      myservo.attach(13);
      for (int n = 0; n <= 10; n++) {
        motor.step(-100);
        for (int i = 0; i <= 180; i += 6) {
          myservo.write(i);
          if (highVisible < SI1145.ReadIR()) {
            servoPos = i;
            stepPos = n*100; //multiply by number of motor.step("")
            highVisible = SI1145.ReadIR();
          }
          Serial.println(SI1145.ReadIR());
          if (i == 180) {
            break;
          }
        }
        if (n==10) {
        break;
      }
    }
    } else {
      delaystate = false;
    }
  myservo.write(servoPos);
  stepPos = 1000-stepPos;
  motor.step(stepPos);
  Serial.println(highVisible);
  }
}
