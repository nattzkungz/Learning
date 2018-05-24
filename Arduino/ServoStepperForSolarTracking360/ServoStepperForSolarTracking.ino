// servo setup
#include <Servo.h>
Servo myservo;
// light sensor setup
#include "Arduino.h"
#include "SI114X.h"
#include <Wire.h>

SI114X SI1145 = SI114X();

//StepperMotor
#include <StepperMotor.h>
StepperMotor motor(8,9,10,11);

//barometer
#include <dht.h>
#define DHT11_PIN 7

#define BME280_ADDRESS 0x76
unsigned long int hum_raw,temp_raw,pres_raw;
signed long int t_fine;
const double sea_press = 1013.25;
float getAltitude;

uint16_t dig_T1;
 int16_t dig_T2;
 int16_t dig_T3;
uint16_t dig_P1;
 int16_t dig_P2;
 int16_t dig_P3;
 int16_t dig_P4;
 int16_t dig_P5;
 int16_t dig_P6;
 int16_t dig_P7;
 int16_t dig_P8;
 int16_t dig_P9;
 int8_t  dig_H1;
 int16_t dig_H2;
 int8_t  dig_H3;
 int16_t dig_H4;
 int16_t dig_H5;
 int8_t  dig_H6;

//variable
int servoPos;
int stepPos;
int highVisible = 0;
int i = 0;
int n = 0;

void setup() {
  //Barometer Setup
  uint8_t osrs_t = 1;             //Temperature oversampling x 1
  uint8_t osrs_p = 1;             //Pressure oversampling x 1
  uint8_t osrs_h = 1;             //Humidity oversampling x 1
  uint8_t mode = 3;               //Normal mode
  uint8_t t_sb = 5;               //Tstandby 1000ms
  uint8_t filter = 0;             //Filter off
  uint8_t spi3w_en = 0;           //3-wire SPI Disable

  uint8_t ctrl_meas_reg = (osrs_t << 5) | (osrs_p << 2) | mode;
  uint8_t config_reg    = (t_sb << 5) | (filter << 2) | spi3w_en;
  uint8_t ctrl_hum_reg  = osrs_h;

  Wire.begin();

  writeReg(0xF2,ctrl_hum_reg);
  writeReg(0xF4,ctrl_meas_reg);
  writeReg(0xF5,config_reg);
  readTrim();
  //Light Sensor and servo
  motor.setStepDuration(1);
  SI1145.Begin();
  Serial.begin(9600);
  myservo.attach(13);
  for (int n = 0; n <= 41; n++) {
    motor.step(-100);
    for (int i = 0; i <= 180; i += 6) {
      myservo.write(i);
      if (highVisible < SI1145.ReadIR()) {
        servoPos = i;
        stepPos = n*100; //multiply by number of motor.step("")
        highVisible = SI1145.ReadIR();
      }
      Serial.println(SI1145.ReadIR());
      delay(50);
      if (i == 180) {
        break;
      }
    }
    delay(10);
    if (n==10) {
       break;
    }
  }
  myservo.write(servoPos);
  stepPos = 3600-stepPos;
  motor.step(stepPos);
  Serial.println(highVisible);
}
void loop() {
  // put your main code here, to run repeatedly:
}
