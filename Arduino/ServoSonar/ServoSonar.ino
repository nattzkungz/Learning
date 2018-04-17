#include <Servo.h>
#define echoPin 7
#define trigPin 8
#define ledOn 13

long duration;
long distance;

Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(13);
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledOn, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);

  distance = duration/58.2;

  Serial.println(distance);
}
