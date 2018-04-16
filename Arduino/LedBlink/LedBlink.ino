// the setup function runs once when you press reset or power the board
int LedOn = 13;

void setup() {
  pinMode(LedOn, OUTPUT);
}

void loop() {
  digitalWrite(LedOn, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LedOn, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
