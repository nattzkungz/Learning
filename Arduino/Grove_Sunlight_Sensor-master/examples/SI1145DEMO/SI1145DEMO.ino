/*
    This is a demo to test Grove - Sunlight Sensor library

*/

#include <Wire.h>

#include "Arduino.h"
#include "SI114X.h"
float uv;

SI114X SI1145 = SI114X();

void setup() {

  Serial.begin(9600);
  Serial.println("Beginning Si1145!");

  while (!SI1145.Begin()) {
    Serial.println("Si1145 is not ready!");
    delay(1000);
  }
  Serial.println("Si1145 is ready!");
}

void loop() {
  Serial.print("//--------------------------------------//\r\n");
  Serial.print("Vis: "); Serial.println(SI1145.ReadVisible());
  Serial.print("IR: "); Serial.println(SI1145.ReadIR());
  //the real UV value must be div 100 from the reg value , datasheet for more information.
  uv = (float)SI1145.ReadUV()/100;
  Serial.print("UV: ");  Serial.println(uv);
  if (uv <= 3) {
    Serial.print("Warning:"); Serial.println("Wear Sun Glass; Low UV");
  } else if (uv > 3 && uv <= 6) {
    Serial.print("Warning:"); Serial.println("Take cover when avalible; Moderate UV");
  } else if (uv > 6 && uv >= 8) {
    Serial.print("Warning:"); Serial.println("Apply SPF 30+ sunscreen, don't stay out more than 3 hours; High UV");
  } else if (uv > 8 && uv >= 11) {
    Serial.print("Warning:"); Serial.println("Do not stay in the sun for too long; Very High UV");
  } else {
    Serial.print("Warning:"); Serial.println("Take all Percautions; Extreme UV");
  }
  delay(1000);
}

