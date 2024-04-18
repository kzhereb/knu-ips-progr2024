/*
 * lesson_2024_04_18_bitvector.cpp
 *
 *  Created on: Apr 18, 2024
 *      Author: KZ
 */

#include <iostream>

namespace lesson_2024_04_18_bitvector {

void demo_number_representation() {
  unsigned decimal = 15;
  unsigned hex = 0xF;
  unsigned binary = 0b1111;
  unsigned octal = 017;

  std::cout<< "decimal="<<decimal<<std::endl;
  std::cout<< "hex="<<hex<<std::endl;
  std::cout<< "binary="<<binary<<std::endl;
  std::cout<< "octal="<<octal<<std::endl;
}

int main() {
  demo_number_representation();
  return 0;
}

}


