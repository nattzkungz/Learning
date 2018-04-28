#include <iostream>
int x;
int y;
int z;
int main(int argc, char const *argv[]) {
  std::cin >> x;
  y = x % 3;
  z = x % 4;

  if (z == 0) {
    std::cout << "Divided by 4" << '\n';
  } else if (y == 0) {
    std::cout << "Divided by 3" << '\n';
  } else {
    std::cout << "cannot" << '\n';
  }
  return 0;
}
