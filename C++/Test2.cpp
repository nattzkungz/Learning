#include "iostream"

int main(int argc, char const *argv[]) {

  int age;

  std::cout << "what is your age?" << '\n';
  std::cin >> age;

  switch (age) {
    case 16:
     std::cout << "fuck you" << '\n';
     break;

     case 18:
     std::cout << "heloo" << '\n';
     break;

     default :
     std::cout << "kuay" << '\n';
  }
  return 0;
}
