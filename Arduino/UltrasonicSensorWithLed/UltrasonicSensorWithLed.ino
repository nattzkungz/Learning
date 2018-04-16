#define echoPin 7
#define trigPin 8
#define ledOn 13

long duration;
long distance;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledOn, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);

  distance = duration/58.2;

  Serial.println(distance);

  delay(50);

  if (distance<18) {
    digitalWrite(ledOn, HIGH);
    delay (30000);
    digitalWrite(ledOn, LOW);
  }
}

