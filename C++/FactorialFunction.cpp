#include <iostream>

int factorial(int a, int n);
double f = 5;
double m;

int main(int argc, char const *argv[]) {
  for (size_t x = 0; x < 20; x++) {
    f = m * x;
    std::cout << f << '\n';
  }
  return 0;
}
