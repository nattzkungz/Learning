#include <stdint.h>
#include <itoa_ljust.h>
#include <int96.h>

int n, m;
void setup() {
  Serial.begin(9600);
}

void loop() {
  n = 1;
  m = 3000;
  
  for(int x = n; x <= m; x++)
  {
    Serial.println(x);
    delay(1);
  }
}
