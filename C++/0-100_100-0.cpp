#include <iostream>

int x;
int y;

int main(int argc, char const *argv[]) {
  for (x = 0, y = 200; x <= 200, y>= 0; x++, y--) {
    std::cout << x << " * " << y << " = " << x*y <<'\n';
  }

}
