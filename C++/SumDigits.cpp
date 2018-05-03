#include <iostream>
int x;
int size = 0;
int sum = 0;

int arrayDigits[10] = {0};

int sumDigits() {
  std::cin >> x;
  while (x>0) {
    int Digits = x%10;
    x /= 10;
    //std::cout << "These are the Digits " << Digits << '\n';
    arrayDigits[size] = Digits;
    ++size;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  sumDigits();
  std::cout << "Sum" << '\n';
  for (int i = 0; i < size; i++) {
    sum += arrayDigits[i];
  }
  std::cout << sum << '\n';
  return 0;
}
