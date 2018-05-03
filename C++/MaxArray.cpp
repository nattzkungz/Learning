#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
  int Array [] = { 1, 2, 5, 7};
  std::cout << Array[3] << '\n';
  std::cout << *std::max_element(Array, Array+4) << '\n';

  return 0;
}
