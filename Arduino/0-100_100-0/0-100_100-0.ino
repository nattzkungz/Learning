long x, y;
void setup() {
    Serial.begin(9600);
  for (x = 0, y = 200; x <= 200, y >= 0; x++, y--) {
    Serial.print(x);
    Serial.print(" * ");
    Serial.print(y);
    Serial.print(" = ");
    Serial.println(x * y);
    delay(10);
  }
}

void loop() {}
