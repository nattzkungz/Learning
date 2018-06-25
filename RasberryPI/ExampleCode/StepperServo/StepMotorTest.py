import pigpio
from PigpioStepperMotor import StepperMotor, fullStepSequence

#Variables
previousMillis = 0
interval = 0.5
delaystate = false

pi = pigpio.pi()
motor = StepperMotor(pi, 6, 13, 19, 26, sequence = fullStepSequence)
for i in range(512):
  motor.doCounterclockwiseStep()
  motor.doCounterclockwiseStep()
