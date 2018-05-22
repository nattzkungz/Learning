#include <StepperMotor.h>

StepperMotor motor(8,9,10,11);

void setup(){
  Serial.begin(9600);
  motor.setStepDuration(1);
  for (size_t i = 0; i <= 10; i++) {
    motor.step(-30);
    if (i==10) {
      break;
    }
  }
}

void loop(){

}

