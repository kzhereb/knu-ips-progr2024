/*
 * lesson_2024_03_07_sorting.cpp
 *
 *  Created on: Mar 7, 2024
 *      Author: KZ
 */

#include <iostream>
#include <cmath>
#include <cassert>

namespace lesson_2024_03_07_sorting {

void print_array(int* array, size_t size, size_t items_to_print = 5) {
  if (size <= items_to_print*2) {
    for(size_t i = 0; i<size; i++) {
      std::cout<<array[i]<<" ";
    }
  } else {
    for(size_t i = 0; i < items_to_print; i++) {
      std::cout<<array[i]<<" ";
    }
    std::cout<<"... ";
    for(size_t i = size-items_to_print; i < size; i++) {
      std::cout<<array[i]<<" ";
    }
  }
  std::cout<<"size="<<size<<std::endl;
}

int* square_selection_sort(int* array, size_t size) {
  int* sorted = new int[size];
  size_t block_size = std::sqrt(size); // |B_i| in slides
  size_t num_blocks = std::sqrt(size); // m in slides
  assert( size == num_blocks*block_size); //TODO: change it, in general case not true
  int* min_in_block = new int[num_blocks]; // g_i in slides

  for (size_t i = 0; i < num_blocks; i++) {
    //int min_value = ???
    for(size_t j = i*block_size; j < (i+1)*block_size; j++) {

    }
  }


  //print_array(sorted, size);
  return sorted;
}


int main() {
  int* array = new int[100];
  print_array(array, 100);
  return 0;
}



}

