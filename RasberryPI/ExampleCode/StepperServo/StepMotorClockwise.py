var stepperWiringPi = require("../src/stepper-wiringpi");
var pinIN1 = 6;  // Stepper Red
var pinIN2 = 13;  // Stepper Blue
var pinIN3 = 19 ;// Stepper Green
var pinIN4 = 26; // Stepper Black
var motor = stepperWiringPi.setup(64, pinIN1, pinIN2, pinIN3, pinIN4);

motor.setSpeed(60);
motor.step(64);
motor.stop();
