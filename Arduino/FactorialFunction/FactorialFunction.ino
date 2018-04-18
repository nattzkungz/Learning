#include <stdint.h>
#include <itoa_ljust.h>
#include <int96.h>

int n, m;
void setup() {
  Serial.begin(115200);
}

void loop() {
  n = 1;
  m = 100;

  uint64_t fact = 1;
  for(int x = n; x <= m; x++)
  {
    fact = fact * x;
    Serial.print("The Factorial of ");
    Serial.print(x);
    Serial.print(" is ");
    Serial.println(fact);
    delay(100);
  }

}
