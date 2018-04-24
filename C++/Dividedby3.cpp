#include <iostream>

int x,y;

int main(int argc, char const *argv[]) {
        for (size_t x = 1; x < 16; x++) {
                y=x%3;
                if (y==0) {
                        std::cout << "Fizz" << '\n';
                } else {
                        std::cout << x << '\n';
                }
        }
        return 0;
}
