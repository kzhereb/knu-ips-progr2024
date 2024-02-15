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

  //Node() = default;

  Node(int value_el, Node* prev_el = nullptr, Node* next_el = nullptr) {
    value = value_el;
    prev = prev_el;
    next = next_el;
  }
};

bool search(Node* start, int value) {
  while(start) {
    if (start->value == value) { return true; }
    start = start->next;
  }
  return false;
}

void push_back(Node* start, Node*& end, int value){
  while(start->next) {
    start = start->next;
  }
  Node* new_node = new Node(value, start);
  start->next = new_node;

  end = new_node;
}

void print(Node* start)
{
    Node *current = start;
    while(current != nullptr)
    {
        std::cout << current->value << " ";
        current = current -> next;
    }
    std::cout << std::endl;
}

int main() {

  // create list  [1, 3, 5]
  Node* start = new Node(1);
  start->next = new Node(3, start);

  Node* end = new Node(5, start->next);
  start->next->next = end;

  std::cout<<"middle from start " << start->next->value<<"\n";
  std::cout<<"middle from end " << end->prev->value<<std::endl;

  print(start);

  std::cout<<"searching for 2, result="<<std::boolalpha<<search(start, 2)<<std::endl;
  std::cout<<"searching for 5, result="<<std::boolalpha<<search(start, 5)<<std::endl;

  std::cout<<"push back 7, start="<<start<<std::endl;
  push_back(start, end, 7);
  std::cout<<"last item is "<< end->value<<", start="<<start<<std::endl;
  std::cout<<"printing..."<<std::endl;
  print(start);

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


