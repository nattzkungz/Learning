stepperWiringPi = require("../src/stepper-wiringpi");
pinIN1 = 6;  // Stepper Red
pinIN2 = 13;  // Stepper Blue
pinIN3 = 19 ;// Stepper Green
pinIN4 = 26; // Stepper Black
motor = stepperWiringPi.setup(64, pinIN1, pinIN2, pinIN3, pinIN4);

motor.setSpeed(60);
motor.step(64);
motor.stop();
