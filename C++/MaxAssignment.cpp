#include <iostream>

int main(int argc, char const *argv[]) {
  int x;
  float y = 0;
  std::cout << "Enter a number" << '\n';
  std::cin >> x;

  if ((x + 5) % 3 == 0) {
    std::cout << "Hello" << '\n';
  } else {
    std::cout << "Genuis" << '\n';
    y = +(x + 5) % 3;
    std::cout << y << '\n';
  }
  return 0;
}
