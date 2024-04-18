/*
 * lesson_2024_04_18_bitvector.cpp
 *
 *  Created on: Apr 18, 2024
 *      Author: KZ
 */

#include <iostream>
#include <vector>
#include <cassert>

namespace lesson_2024_04_18_bitvector {

const size_t MAX_BITVECTOR_SIZE = sizeof(unsigned) *8;

struct BinaryVectorGraph {
  std::vector<unsigned> edges_matrix; // in binary format, each row of matrix stored as unsigned

  BinaryVectorGraph(size_t vertex_count) : edges_matrix(vertex_count) {
    assert(vertex_count <= MAX_BITVECTOR_SIZE);
    assert(edges_matrix.size() == vertex_count);
  }
};



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
  //demo_number_representation();
  BinaryVectorGraph graph(5);
  return 0;
}

}


