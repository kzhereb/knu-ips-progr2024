/*
 * lesson_2024_03_28_tree.cpp
 *
 *  Created on: Mar 28, 2024
 *      Author: KZ
 */

#include <vector>
#include <iostream>
#include <cassert>

namespace lesson_2024_03_28_tree {

struct TreeNode {
  int value;
  std::vector<TreeNode*> children;

  TreeNode(int value): value{value}, children{} {}
};


void print_tree(TreeNode* root) {
  assert(root!=nullptr);
  std::cout<<root->value;
  if (root->children.empty()) {return;}
  std::cout<<"(";
  for(TreeNode* child: root->children) {
    print_tree(child);
    std::cout<<" ";
  }
  std::cout<<")";
}

void delete_tree(TreeNode*& root) {
  for(TreeNode*& child: root->children) {
    delete_tree(child);
  }
  delete root;
  root = nullptr;
}

void remove_subtree_by_value(TreeNode*& root, int value) {
  if (root->value == value) {

  }
}

TreeNode* create_demo_tree() {
  TreeNode* root = new TreeNode(1);
  root->children.push_back(new TreeNode(2));
  TreeNode* child = new TreeNode(3);
  child->children.push_back(new TreeNode(5));
  child->children.push_back(new TreeNode(6));
  root->children.push_back(child);
  child = new TreeNode(4);
  child->children.push_back(new TreeNode(7));
  root->children.push_back(child);
  return root;
}

void check_memory_leaks() {
  for(size_t i = 0; i<1e6; i++) {
    TreeNode* root = create_demo_tree();
    delete_tree(root);
  }
  while(true) {}
}

int main() {

  TreeNode* root = create_demo_tree();
  print_tree(root);
  std::cout<<std::endl;

  check_memory_leaks();

  return 0;
}
}

