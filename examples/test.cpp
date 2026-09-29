#include <iostream>
#include "SQType.h"

int main() {
  s16_q12_t q12_number = -2; // fast declaration
  SQType<int16_t, 12> q12_number_2 = 3; // custom declaration
  float as_float = q12_number / q12_number_2;
  std::cout << "Float : " << as_float << "\n";
  return 0;
}