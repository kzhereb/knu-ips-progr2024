/*
 * lesson_2024_02_01_linkedlist.cpp
 *
 *  Created on: Feb 1, 2024
 *      Author: KZ
 */

#include <iostream>


struct Node {
  int value;
  Node* prev;
  Node* next;
};

int main() {
  Node* start = new Node;
  Node* end = new Node;

  // create list  [1, 3, 5]

  start->value = 1;
  //start->prev = new Node;
  start->prev = nullptr;
  start->next = new Node;
  start->next->value = 3;
  start->next->prev = start;
  start->next->next = end;
 // end->prev = new Node;
  //end->next = new Node;
  end->value = 5;
  end->prev = start->next;
  end->next = nullptr;

  std::cout<<"middle from start " << start->next->value<<"\n";
  std::cout<<"middle from end " << end->prev->value<<std::endl;
  return 0;

}

int hello() {
  std::cout << "hello world!\n"; // doesn't flush buffer to stdout - can miss message
  std::cout.flush(); // forces buffer to stdout
  //std::cout << "hello world (again)!" << std::endl; //std::endl also flushes buffer
  while(true) { } // endless loop - to show possible issues when buffer is not flushed
  return 0;
}


