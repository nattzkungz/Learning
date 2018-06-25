import time
import SDL_Pi_SI1145

sensor = SDL_Pi_SI1145.SDL_Pi_SI1145()
from datetime import datetime

pulse = None
gpioServo = 4
servoPos = None
highVisible = 0
stepPos = None

import pigpio
from PigpioStepperMotor import StepperMotor, fullStepSequence

pi = pigpio.pi()
motor = StepperMotor(pi, 6, 13, 19, 26, sequence = fullStepSequence, delayAfterStep = 0.05)

for i in range(1024):
  motor.doClockwiseStep()
  time.sleep(0.1)
  for x in range(21):
    #pulse = (x * 100)+500   #turn  servo 100 pulse from 500-2500
    #pi.set_servo_pulsewidth(gpioServo, pulse)
    #time.sleep(0.025)
    vis = sensor.readVisible()
    IR = sensor.readIR()
    UV = sensor.readUV()
    uvIndex = UV / 100.0
    if highVisible < uvIndex:
        servoPos = x
        stepPos = i
        highVisible = uvIndex
    print('SunLight Sensor read at time: %s' % datetime.now())
    print '		Vis:             ' + str(vis)
    print '		IR:              ' + str(IR)
    print '		UV Index:        ' + str(uvIndex)

    if uvIndex <= 3 :
        print "Warning:" + "Wear Sun Glass; Low UV"
    elif uvIndex > 3 and uvIndex <= 6 :
        print "Warning:" + "Take cover when avalible; Moderate UV"
    elif uvIndex > 6 and uvIndex >= 8 :
        print "Warning:" + "Apply SPF 30+ sunscreen, don't stay out more than 3 hours; High UV"
    elif uvIndex > 8 and uvIndex >= 11 :
        print "Warning:" + "Do not stay in the sun for too long; Very High UV"
    else :
        print "Warning:" + "Take all Percautions; Extreme UV"
'''
if __name__ == '__main__':
    servoPos = (servoPos * 100)+500
    stepPos = 256 - stepPos
    pi.set_servo_pulsewidth(gpioServo, servoPos)
    for i in range(256):
      motor.doClockwiseStep()
      motor.doClockwiseStep()
      motor.doClockwiseStep()
      motor.doClockwiseStep()
    print(servoPos)
    time.sleep(1)
    pi.set_servo_pulsewidth(gpioServo, 0)
    pi.stop()
'''
