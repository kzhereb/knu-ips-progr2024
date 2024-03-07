/*
 * lesson_2024_03_07_sorting.cpp
 *
 *  Created on: Mar 7, 2024
 *      Author: KZ
 */

#include <iostream>

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
  //print_array(sorted, size);
  return sorted;
}


int main() {
  int* array = new int[100];
  print_array(array, 100);
  return 0;
}



}

