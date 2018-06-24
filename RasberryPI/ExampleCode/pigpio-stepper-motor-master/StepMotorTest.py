import pigpio
from PigpioStepperMotor import StepperMotor, fullStepSequence

#Variables
previousMillis = 0
interval = 0.5
delaystate = False

pi = pigpio.pi()
motor = StepperMotor(pi, 6, 13, 19, 26, sequence = fullStepSequence, delayAfterStep = 0)
  if currentMillis - previousMillis > interval :
    // save the last time the servo turn
    previousMillis = currentMillis
    if delaystate = False :
      delayState = True
      for i in range(512):
        motor.doCounterclockwiseStep()
        motor.doCounterclockwiseStep()
