int my_power;
int answer;
int x;
int y;


void setup() {
  Serial.begin(9600);
  answer = power(3, 2);

  Serial.println(answer);
}

int power(int x, int y) {
  if (y==0) {
    Serial.print("1");
  } else {
    for (int n = 1; n < y; n++) {
      x = x * x;
    }
    return x;  }
}


void loop() {

}
