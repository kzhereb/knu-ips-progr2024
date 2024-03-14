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

// returns pair: min_value, index
//std::pair<int, size_t> find_min(int* array, size_t size)

int find_min(int *arr, size_t arr_size, size_t &index) {
  int min_value = arr[0];
  index = 0;

  for (size_t i = 1; i < arr_size; ++i) {
    if (arr[i] < min_value) {
      min_value = arr[i];
      index = i;
    }
  }

  return min_value;
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

  //[3, 7, 12, 1, 8, 2, 5, 123, 1, 42]
  int array2[] = {3, 7, 12, 1, 8, 2, 5, 123, 1, 42};
  size_t size2 = (sizeof array2) / (sizeof array2[0]);
  std::cout<<size2<<std::endl;
  size_t min_index=0;
  int min_value = find_min(array2, size2, min_index);
  std::cout<<"Min item "<<min_value<<" at position "<<min_index<<std::endl;
  return 0;
}



}

