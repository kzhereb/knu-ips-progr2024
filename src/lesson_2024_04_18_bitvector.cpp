/*
 * lesson_2024_04_18_bitvector.cpp
 *
 *  Created on: Apr 18, 2024
 *      Author: KZ
 */

#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>

namespace lesson_2024_04_18_bitvector {

const size_t MAX_BITVECTOR_SIZE = sizeof(unsigned) *8;


void set_bit(unsigned& row, size_t position) {
  row = row | (1 << position);
}

struct BinaryVectorGraph {
  std::vector<unsigned> edges_matrix; // in binary format, each row of matrix stored as unsigned

  BinaryVectorGraph(size_t vertex_count) : edges_matrix(vertex_count) {
    assert(vertex_count <= MAX_BITVECTOR_SIZE);
    assert(edges_matrix.size() == vertex_count);
  }

  void add_edge(size_t from, size_t to) {
    assert(from < edges_matrix.size());
    assert(to < edges_matrix.size());

    set_bit(edges_matrix[from], to);
  }
};


//has_edge


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

void demo_binary_operations() {
  unsigned input = 0b110;
  unsigned expected = 0b1100; // NOT 0b101
  unsigned actual = input<<1;

  std::cout<<"expected = " <<std::bitset<8>(expected)<<std::endl;
  std::cout<<"actual = " <<std::bitset<8>(actual)<<std::endl;
  assert(expected == actual);

  input = 0b1001;
  expected = 0b1101;
  actual = input | 0b0100;
  std::cout<<"expected = " <<std::bitset<8>(expected)<<std::endl;
  std::cout<<"actual = " <<std::bitset<8>(actual)<<std::endl;
  assert(expected == actual);

  input = 2;
  expected = 0b0100;
  actual = 1 << input ;
  std::cout<<"expected = " <<std::bitset<8>(expected)<<std::endl;
  std::cout<<"actual = " <<std::bitset<8>(actual)<<std::endl;
  assert(expected == actual);

  input = 0b1001;
  size_t position = 2;
  expected = 0b1101;
  actual = input | ( 1 << position);
  std::cout<<"expected = " <<std::bitset<8>(expected)<<std::endl;
  std::cout<<"actual = " <<std::bitset<8>(actual)<<std::endl;
  assert(expected == actual);

  input = 0b1001;
  position = 2;
  expected = 0b1101;
  actual = input;
  set_bit(actual, position);
  std::cout<<"expected = " <<std::bitset<8>(expected)<<std::endl;
  std::cout<<"actual = " <<std::bitset<8>(actual)<<std::endl;
  assert(expected == actual);



}

int main() {
  //demo_number_representation();
  demo_binary_operations();
  BinaryVectorGraph graph(5);

  return 0;
}

}


