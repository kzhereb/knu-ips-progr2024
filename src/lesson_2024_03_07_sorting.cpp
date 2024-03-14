/*
 * lesson_2024_03_07_sorting.cpp
 *
 *  Created on: Mar 7, 2024
 *      Author: KZ
 */

#include <iostream>
#include <cmath>
#include <cassert>
#include <climits>

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

void print_array(size_t* array, size_t size, size_t items_to_print = 5) {
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
// finds min value in subarray from start (inclusive) to end (inclusive)
int find_min_subarray(int *arr, size_t start, size_t end, size_t &index) {
  int min_value = arr[start];
  index = start;

  for (size_t i = start+1; i <= end; ++i) {
    if (arr[i] < min_value) {
      min_value = arr[i];
      index = i;
    }
  }

  return min_value;
}

int* square_selection_sort(int* array, size_t size) {
  int* sorted = new int[size];

  //step 1: divide into blocks of same size
  size_t block_size = std::sqrt(size); // |B_i| in slides
  size_t num_blocks = std::sqrt(size); // m in slides
  assert( size == num_blocks*block_size); //TODO: change it, in general case not true
  int* min_in_block = new int[num_blocks]; // g_1, ..., g_m in slides
  size_t* min_index_in_block = new size_t[num_blocks];

  // step2: find minimums in blocks
  for (size_t i = 0; i < num_blocks; i++) {
    //int min_value = ???
    size_t block_start = i*block_size;
    size_t index;
    min_in_block[i] = find_min(array + block_start, block_size, index );
    //std::cout<<"in block "<<i<<" min is "<<min_in_block[i]<<" and index is "<<index<<std::endl;
    min_index_in_block[i] = index + block_start;
  }
  //print_array(min_in_block, num_blocks);
  //print_array(min_index_in_block, num_blocks);

  //step 3: find min of mins
  size_t global_min_index; // i in slides
  int global_min = find_min(min_in_block, num_blocks, global_min_index); // g_i in slides

  //std::cout<<"global min = "<<global_min<<" in position "<<global_min_index<<std::endl;

  //step 4: move minimum to sorted, remove it from starting array, replace with new minimum
  sorted[0] = global_min;

  size_t index_of_min = min_index_in_block[global_min_index];
  array[index_of_min] = INT_MAX; // replace with max possible value - it will not become new minimum

  size_t block_start = global_min_index*block_size;
  size_t index;
  min_in_block[global_min_index] = find_min(array + block_start, block_size, index );
  min_index_in_block[global_min_index] = index + block_start;

  print_array(array, size);
  print_array(sorted, size);



  //print_array(sorted, size);
  return sorted;
}

void array_syntax_demo(int array2[]) {
  assert(array2 + 1 == &array2[1]);
  assert(*(array2 + 1) == array2[1]);
  assert(*(1 + array2) == array2[1]);
  assert(*(1 + array2) == 1[array2]);
  assert(array2[1] == 1[array2]);
  std::cout << array2[2] << " " << 2[array2] << std::endl; // never do this in real code :)
}

int main() {
  int* array = new int[100];
  print_array(array, 100);
  size_t size = (sizeof array) / (sizeof array[0]);
  std::cout<<size<<std::endl;

  //[3, 7, 12, 1, 8, 2, 5, 123, 1, 42]
  int array2[] = {-3, 7, 12, 1, 8, 2, 5, 123, 1, 42};
  size_t size2 = (sizeof array2) / (sizeof array2[0]);
  std::cout<<size2<<std::endl;
  size_t min_index=0;
  int min_value = find_min(array2, size2, min_index);
  std::cout<<"Min item "<<min_value<<" at position "<<min_index<<std::endl;
  min_value = find_min_subarray(array2, 4, 7, min_index);
  std::cout<<"Min item in subarray "<<min_value<<" at position "<<min_index<<std::endl;

  min_value = find_min(&(array2[1]), size2-1, min_index);
  std::cout<<"Min item "<<min_value<<" at position "<<min_index<<std::endl;

  min_value = find_min(array2+1, size2-1, min_index);
  std::cout<<"Min item "<<min_value<<" at position "<<min_index<<std::endl;

  min_value = find_min(array2+4, 4 /*7+1-4*/, min_index);
  std::cout<<"Min item in subarray using find_min "<<min_value<<" at position "<<min_index+4<<std::endl;

  square_selection_sort(array2, 9); // ignore last item, we need size that is full square

  return 0;
}



}

