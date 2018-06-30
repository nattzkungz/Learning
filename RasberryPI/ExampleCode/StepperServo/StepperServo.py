import time
import SDL_Pi_SI1145

sensor = SDL_Pi_SI1145.SDL_Pi_SI1145()
from datetime import datetime

from apscheduler.schedulers.background import BackgroundScheduler

pulse = None
gpioServo = 4
servoPos = None
highVisible = 0
stepPos = None

import pigpio
from PigpioStepperMotor import StepperMotor, fullStepSequence

def Stepper():
pi = pigpio.pi()
motor = StepperMotor(pi, 6, 13, 19, 26, sequence = fullStepSequence)
for i in range(2048):
  motor.doClockwiseStep()

def Servo():
  for x in range(21):
    pulse = (x * 100)+500   #turn  servo 100 pulse from 500-2500
    pi.set_servo_pulsewidth(gpioServo, pulse)
    time.sleep(0.025)

def servoDelay():
    if pulse == 2500:
        delay = 0.5
    else:
        delay = 0.025
    print(delay)
def Sensor():
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



if __name__ == '__main__':
    scheduler = BackgroundScheduler()
    scheduler.add_job(Sensor, 'interval', seconds=0.025)
    scheduler.add_job(Stepper, 'interval', seconds=0.025)
    scheduler.add_job(Servo, 'interval', seconds=0.025)
    scheduler.add_job(servoDelay, 'interval', seconds=0.025)
