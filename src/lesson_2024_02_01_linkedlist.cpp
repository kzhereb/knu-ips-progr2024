/*
 * lesson_2024_02_01_linkedlist.cpp
 *
 *  Created on: Feb 1, 2024
 *      Author: KZ
 */

#include <iostream>
#include <iomanip>


struct Node {
  int value;
  Node* prev;
  Node* next;
};

bool search(Node* start, int value) {
  while(start) {
    if (start->value == value) { return true; }
    start = start->next;
  }
  return false;
}

void push_back(Node* start, int value){
  while(start->next) {
    start = start->next;
  }
  Node* new_node = new Node;
  new_node->value = value;
  start->next = new_node;
}

int main() {


  Node* start = new Node;
  Node* end = new Node;

  // create list  [1, 3, 5]

  start->prev = nullptr;
  start->value = 1;
  start->next = new Node;

  start->next->prev = start;
  start->next->value = 3;
  start->next->next = end;

  end->prev = start->next;
  end->value = 5;
  end->next = nullptr;


  std::cout<<"middle from start " << start->next->value<<"\n";
  std::cout<<"middle from end " << end->prev->value<<std::endl;

  std::cout<<"searching for 2, result="<<std::boolalpha<<search(start, 2)<<std::endl;
  std::cout<<"searching for 5, result="<<std::boolalpha<<search(start, 5)<<std::endl;

  push_back(start, 7);

  delete start;
  delete end->prev;
  delete end;


  return 0;

}

int hello() {
  std::cout << "hello world!\n"; // doesn't flush buffer to stdout - can miss message
  std::cout.flush(); // forces buffer to stdout
  //std::cout << "hello world (again)!" << std::endl; //std::endl also flushes buffer
  while(true) { } // endless loop - to show possible issues when buffer is not flushed
  return 0;
}


