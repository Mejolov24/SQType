#include <iostream>
#include <SQType.h>

int main() {
  s16_q12_t q12_number = 1; // common declaration
  SQType<int16_t, 12> q12_number_2 = 3; // custom declaration
  float as_float = q12_number / q12_number_2;
  std::cout << "1 / 3 = " << as_float << "\n";
  float as_float_2 = q12_number / s16_q12_t(2);
  std::cout << "1 / 2 = " << as_float_2 << "\n";
  return 0;
}