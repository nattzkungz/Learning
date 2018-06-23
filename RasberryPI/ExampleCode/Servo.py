import time

import pigpio

pi = pigpio.pi() # Connect to local Pi.

pulse = None

for x in range(200):
    pulse = x * 10
    time.sleep(0.2)
    pi.set_servo_pulsewidth(4, pulse)
    pass


'''
pi.set_servo_pulsewidth(4, 1000)
time.sleep(2)
pi.set_servo_pulsewidth(4, 1500)
time.sleep(2)
pi.set_servo_pulsewidth(4, 2000)
time.sleep(2)
pi.set_servo_pulsewidth(4, 1500)
time.sleep(2)

# switch servo off
pi.set_servo_pulsewidth(4, 0);
'''

pi.stop()
