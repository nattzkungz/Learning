#include <iostream>

int size = 10;
int *p = &size; //ประกาศตัวแปล pointer : การใช้ $ : int *p = &size แทนที่จะเก็บค่าของ size, &size จะเก็บ adress
int y = *p; //การใช้ * : int y = *p : * จะเปิดเข้าไปใน addressและขึ้นค่าที่อยู่ใน adress แต่ถ้าไม่มี * ก็จะขึ้น adress ของ p

int main(int argc, char const *argv[]) {
  std::cout << y << '\n';
  *p = 456; //เปลี่ยนค่าใน address โดยใช้ pointer
  std::cout << size << '\n';
  return 0;
}
