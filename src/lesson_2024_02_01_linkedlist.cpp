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

  for(int i=0; i < 1000000; i++) {
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

  delete start;
  delete end->prev;
  delete end;
  }
//  std::cout<<"middle from start " << start->next->value<<"\n";
//  std::cout<<"middle from end " << end->prev->value<<std::endl;
//  std::cout<<"sizeof pointer " << sizeof(start)<<std::endl;
//  std::cout<<"sizeof struct " << sizeof(*start)<<std::endl;
//  std::cout<<"sizeof int " << sizeof(start->value)<<std::endl;
//  std::cout<<"sizeof pointer " << sizeof(Node*)<<std::endl;
//  std::cout<<"sizeof struct " << sizeof(Node)<<std::endl;
//  std::cout<<"sizeof int " << sizeof(int)<<std::endl;
//  //std::cout<<"sizeof start->next " << sizeof(start->next)<<std::endl;
//


  while(true) { }


  return 0;

}

int hello() {
  std::cout << "hello world!\n"; // doesn't flush buffer to stdout - can miss message
  std::cout.flush(); // forces buffer to stdout
  //std::cout << "hello world (again)!" << std::endl; //std::endl also flushes buffer
  while(true) { } // endless loop - to show possible issues when buffer is not flushed
  return 0;
}


