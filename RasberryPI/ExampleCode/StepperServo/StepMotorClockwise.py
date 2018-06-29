stepperWiringPi = require("../src/stepper-wiringpi")
pinIN1 = 6
pinIN2 = 13
pinIN3 = 19
pinIN4 = 26
motor = stepperWiringPi.setup(64, pinIN1, pinIN2, pinIN3, pinIN4)

motor.setSpeed(60)
motor.step(64)
motor.stop()
