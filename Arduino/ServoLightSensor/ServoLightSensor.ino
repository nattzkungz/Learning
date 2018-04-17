#include <Servo.h>
Servo myservo;

int ledPin = 11;
int pos = 0;
int posnow [] = {};
int servo [] = {};
int n = 0;
int array [] = { 1, 2, 5, 7};

void setup() {
  myservo.attach(13);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    n += 1;
    posnow [n] = pos;
    servo [n] = analogRead(ledPin);
    analogWrite(ledPin, analogRead(ledPin)/2);
    max(array, 20);
    delay(15);

  }
  /*for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }*/
  Serial.println(pos);
}
