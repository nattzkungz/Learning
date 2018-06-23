import time

import pigpio

pi = pigpio.pi() # Connect to local Pi.

pulse = None
gpioServo = 4

for x in range(20):
    pulse = (x * 100)+500   #turn  servo 100 pulse from 500-2500
    time.sleep(0.2)
    pi.set_servo_pulsewidth(gpioServo, pulse)
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
