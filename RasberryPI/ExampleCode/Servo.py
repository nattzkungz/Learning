import time

import pigpio

pi = pigpio.pi() # Connect to local Pi.

pulse = None
gpioServo = 4
servoPos = None

for x in range(40):
    pulse = (x * 50)+500   #turn  servo 100 pulse from 500-2500
    servoPos = x*9
    pi.set_servo_pulsewidth(gpioServo, pulse)
    print(servoPos)
    time.sleep(1)
    pass


'''
pi.set_servo_pulsewidth(gpioServo, 1000)
time.sleep(2)
pi.set_servo_pulsewidth(gpioServo, 1500)
time.sleep(2)
pi.set_servo_pulsewidth(gpioServo, 2000)
time.sleep(2)
pi.set_servo_pulsewidth(gpioServo, 1500)
time.sleep(2)

# switch servo off
pi.set_servo_pulsewidth(4, 0);
'''

pi.stop()
