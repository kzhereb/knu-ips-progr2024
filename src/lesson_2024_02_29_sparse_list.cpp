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
  int total_size;
  int default_value=0;

  SparseList(Node* start = nullptr, Node* end = nullptr, int total_size = 0, int default_value = 0):
    start(start), end(end), total_size(total_size), default_value(default_value) {}
};

// adds item at given position, which should be at the end of list
// value can be default, in this case list size is increased, but new node is not added
void push_back(SparseList& list, int value, int position) {
  assert(position >= 0);
  assert(position >= list.total_size);
  if(list.end != nullptr) {
    assert(list.end->position < position);
  }
  list.total_size = position + 1;
  if (value == list.default_value) { // adding default value - no need to add node
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
  result.total_size = input.size();
  return result;
}

// returns position of first item with default value
// if not found - returns -1
int find_first_default(SparseList list) {
  Node* current = list.start;
  if (current->position != 0) { return 0; } // first item is default
  int prev_position = current->position;
  current = current->next;
  while(current) {
    if (current->position - prev_position != 1) { return prev_position + 1; }
    prev_position = current->position;
    current = current->next;
  }
  if (prev_position + 1 == list.total_size) {
    return -1; // this means default value not found at all
  }
  return prev_position + 1;
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
  for(int i = index; i < list.total_size; i++) {
    std::cout<< list.default_value << " ";
  }
  std::cout << std::endl;
}

void print_as_linked_list(SparseList list) {
  Node* current = list.start;
  while (current) {
    std::cout<< current->value << "["<<current->position<<"] ";
    current = current->next;
  }
  std::cout<<"total_size = "<<list.total_size<<std::endl;
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
  print_as_linked_list(list2);

  std::cout<<"First default at position "<<find_first_default(list2)<<std::endl;

  SparseList in_middle = list_to_sparse_list({1, 1, 0, 2, 0});
  print(in_middle);
  std::cout<<"First default at position "<<find_first_default(in_middle)<<std::endl;

  SparseList at_end = list_to_sparse_list({1, 1, -1, 2, 0, 0});
  print(at_end);
  std::cout<<"First default at position "<<find_first_default(at_end)<<std::endl;

  SparseList no_defaults = list_to_sparse_list({1, 1, 2});
  print(no_defaults);
  std::cout<<"First default at position "<<find_first_default(no_defaults)<<std::endl;

  return 0;
}


}

