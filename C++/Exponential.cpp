#include <iostream>

int x;
int y;
long my_power;
long answer;

int power(int x, int y) {
  if (y == 0) {
    std::cout << "1" << '\n';
  } else {
    for (int n = 1; n < y; n++) {
      x = x * x;
    }
  }
  return x;
}

int main(int argc, char const *argv[]) {
  // answer = power(3, 2);
  // std::cout << answer << '\n';
  std::cout << "Enter x" << '\n';
  std::cin >> x;
  std::cout << "Enter Y" << '\n';
  std::cin >> y;
  answer = power(x, y);
  std::cout << "Exponent is = " << answer << '\n';
}
