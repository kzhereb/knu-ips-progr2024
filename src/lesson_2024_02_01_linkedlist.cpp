/*
 * lesson_2024_02_01_linkedlist.cpp
 *
 *  Created on: Feb 1, 2024
 *      Author: KZ
 */

#include <iostream>
#include <iomanip>
#include <cassert>


struct Node {
  int value;
  Node* prev;
  Node* next;

  //Node() = default;

//  Node(int value, Node* prev = nullptr, Node* next = nullptr) {
//    this->value = value;
//    this->prev = prev;
//    this->next = next;
//  }

  Node(int value, Node* prev = nullptr, Node* next = nullptr): value(value), prev(prev), next(next) { }
};

bool search(Node* start, int value) {
  while(start) {
    if (start->value == value) { return true; }
    start = start->next;
  }
  return false;
}

void push_back( Node*& end, int value){
  Node* new_node = new Node(value, end);
  end->next = new_node;

  end = new_node;
}

void pop_back(Node*& end) {
  Node* new_end = end->prev;
  delete end;
  end = new_end;
  end->next = nullptr;
}

// returns inserted node, or nullptr if insert_after_me was not found in list
Node* insert(Node* start, Node* insert_after_me, int value) {
  while(start != insert_after_me && start != nullptr) {
    start = start->next;
  }
  if (start == nullptr) {
    return nullptr;
  }
  Node* new_node = new Node(value, start, start->next);
  start->next = new_node;
  new_node->next->prev = new_node;
  return new_node;
}
// position starts from 0 (start of list)
// returns pointer to node at this position, or nullptr if not found
Node* find_by_position(Node* start, int position) {
  if (position<0) {return nullptr;}
  for(int i=0; i<position && start!= nullptr; ++i ) {
    start = start->next;
  }
  return start;
}

// position identifies place between existing items: 0 = before start, 1 - after first item, ...
// returns inserted node, or nullptr if position is larger than size of list
Node* insert(Node*& start, Node*& end, int position, int value) {
  if (position == 0) {
    Node* new_start = new Node(value,nullptr,start);
    start->prev = new_start;
    start = new_start;
    return new_start;
  }
  Node* current = start;
  int current_position = 0;
  while(current != nullptr && current_position < position - 1) {
    current = current->next;
    current_position++;
  }
  if (current == nullptr) {
    return nullptr;
  }
  Node* new_node = new Node(value, current, current->next);
  assert(new_node->next == current->next);
  current->next = new_node;
  if (new_node->next != nullptr) {
    new_node->next->prev = new_node;
  } else {
    assert(current == end);
    end = new_node;
  }
  return new_node;
}

bool remove(Node*& start, Node*& end, int position) {
  Node* current = find_by_position(start, position);
  if (current == nullptr) { return false;}
  if (current != start) {
    assert(current->prev != nullptr);
    current->prev->next = current->next;
  } else {
    start = current->next;
  }
  if (current != end) {
    assert(current->next != nullptr);
    current->next->prev = current->prev;
  } else {
    end = current->prev;
  }
  delete current;
  return true;

}

//
// remove (from middle)
// deconstructor? (remove all items, free memory)

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

void print(Node* start, Node* end) {
  print(start);
  std::cout<<"end value="<<end->value<<std::endl;
}

int main() {

  // create list  [1, 3, 5]
  Node* start = new Node(1);
  start->next = new Node(3, start);

  Node* end = new Node(5, start->next);
  start->next->next = end;

  std::cout<<"middle from start " << start->next->value<<"\n";
  std::cout<<"middle from end " << end->prev->value<<std::endl;

  print(start, end);

  std::cout<<"searching for 2, result="<<std::boolalpha<<search(start, 2)<<std::endl;
  std::cout<<"searching for 5, result="<<std::boolalpha<<search(start, 5)<<std::endl;

  std::cout<<"push back 7, start="<<start<<std::endl;
  push_back( end, 7);
  std::cout<<"last item is "<< end->value<<", start="<<start<<std::endl;
  std::cout<<"printing..."<<std::endl;
  print(start, end);

  std::cout<<"pop back"<<std::endl;
  pop_back(end);
  print(start, end);

  std::cout<<"insert in middle, after 3 (position 2)"<<std::endl;
  Node* inserted = insert(start, end,  2, 123);
  if (inserted) {
    std::cout<<"inserted value "<<inserted->value<<std::endl;
  } else {
    std::cout<<"not inserted"<<std::endl;
  }
  print(start, end);

  std::cout<<"insert at the end, after 5 (position 4)"<<std::endl;
  inserted = insert(start, end, 4, 456);
  if (inserted) {
    std::cout<<"inserted value "<<inserted->value<<std::endl;
  } else {
    std::cout<<"not inserted"<<std::endl;
  }
  print(start, end);

  std::cout<<"insert at the start (position 0)"<<std::endl;
  inserted = insert(start, end, 0, 789);
  if (inserted) {
    std::cout<<"inserted value "<<inserted->value<<std::endl;
  } else {
    std::cout<<"not inserted"<<std::endl;
  }
  print(start, end);

  std::cout<<"find at position 2"<<std::endl;
  Node* found = find_by_position(start, 2);
  if (found) {
    std::cout<<"found node with value="<<found->value<<std::endl;
  } else {
    std::cout<<"not found"<<std::endl;
  }

  std::cout<<"removing at position 2"<<std::endl;
  std::cout<<std::boolalpha<<remove(start, end, 2)<<std::endl;
  print(start, end);

  std::cout<<"removing at start (position 0)"<<std::endl;
  std::cout<<std::boolalpha<<remove(start, end, 0)<<std::endl;
  print(start, end);

  //assert(start != end->prev);

  std::cout<<"start value="<<start->value<<std::endl;
  delete start;
  //std::cout<<"end->prev value="<<end->prev->value<<std::endl;

  delete end->prev;
  std::cout<<"end value="<<end->value<<std::endl;
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


