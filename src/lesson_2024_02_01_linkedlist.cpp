/*
 * lesson_2024_02_01_linkedlist.cpp
 *
 *  Created on: Feb 1, 2024
 *      Author: KZ
 */

#include <iostream>


int main() {
  std::cout << "hello world!\n"; // doesn't flush buffer to stdout - can miss message
  std::cout.flush(); // forces buffer to stdout
  //std::cout << "hello world (again)!" << std::endl; //std::endl also flushes buffer
  while(true) { } // endless loop - to show possible issues when buffer is not flushed
  return 0;
}


