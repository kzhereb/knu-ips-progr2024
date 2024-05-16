/*
 * lesson_2024_02_29_sparse_list.cpp
 *
 *  Created on: Feb 29, 2024
 *      Author: KZ
 */

#include <iostream>
#include <list>
#include <cassert>

namespace lesson_2024_02_29_sparse_list {

struct Node {
  int value;
  int position;
  Node* prev;
  Node* next;

  Node(int value, int position, Node* prev = nullptr, Node* next = nullptr):
    value(value), position(position), prev(prev), next(next) { }
};

struct SparseList {
  Node* start;
  Node* end;
  int default_value=0;

  SparseList(Node* start = nullptr, Node* end = nullptr, int default_value = 0):
    start(start), end(end), default_value(default_value) {}
};

void push_back(SparseList& list, int value, int position) {
  if (position < 0) { return; }
  if(list.end != nullptr && list.end->position > position) {
    return;
  }

  Node* new_node = new Node(value, position, list.end);
  if (list.end == nullptr) {
    assert(new_node->prev == nullptr);
    list.start = new_node;
  } else {
    list.end->next = new_node;
  }
  list.end = new_node;

}

SparseList list_to_sparse_list(std::list<int> input, int default_value = 0) {
  SparseList result;
  result.default_value = default_value;
  //while(current!=nullptr)
  int current_position = 0;
  for(int value: input) {
    if (value != default_value) {
      push_back(result, value, current_position);
    }
    current_position++;
  }
  return result;
}

void print(SparseList list) {
  Node* current = list.start;
  int index = 0;
  while(current) {
    while(current->position > index) {
      std::cout<< list.default_value << " ";
      index++;
    }
    std::cout<<current->value<<" ";
    current = current->next;
    index++;
  }
  std::cout << std::endl;
}



int main(){
  //example 0 1 0 0 2 0 3 0 0 0 0 0 5

  SparseList list;

  push_back(list, 1, 1);
  push_back(list, 2, 4);
  push_back(list, 3, 6);
  push_back(list, 5, 12);

  print(list);

  std::list<int> input {0, 1, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 5};
  SparseList list2 = list_to_sparse_list(input);
  print(list2);

  return 0;
}


}

