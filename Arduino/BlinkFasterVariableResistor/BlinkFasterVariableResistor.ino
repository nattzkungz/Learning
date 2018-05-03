float vol;
int LedOn = 13;
int t;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(115200);
  pinMode(LedOn, OUTPUT);
}
void loop() {
  vol = analogRead(A0);
  double voltage = (double(vol)*5.0)/1023;
  Serial.println(voltage);
  digitalWrite(13, HIGH);
  t = voltage * 100;
  delay(t);
  digitalWrite(13, LOW);
  delay(t);

}
