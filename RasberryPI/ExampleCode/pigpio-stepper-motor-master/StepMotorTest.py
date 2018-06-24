import pigpio
from PigpioStepperMotor import StepperMotor, fullStepSequence
import time

#Variables
previousTime = time.time()
interval = 2
delaystate = False
currentTime = time.time()
pi = pigpio.pi()
motor = StepperMotor(pi, 6, 13, 19, 26, sequence = fullStepSequence, delayAfterStep = 0)

if currentTime - previousTime > interval :
# save the last time the servo turn
    previousTime = currentTime
    if delaystate == False :
        delayState = True
        for i in range(256):
            motor.doCounterclockwiseStep()
            motor.doCounterclockwiseStep()
            motor.doCounterclockwiseStep()
            motor.doCounterclockwiseStep()
