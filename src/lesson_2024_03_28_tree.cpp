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
  std::cout<<"(";
  for(TreeNode* child: root->children) {
    print_tree(child);
    std::cout<<", ";
  }
  std::cout<<")";
}


int main() {

  TreeNode* root = new TreeNode(1);
  root->children.push_back(new TreeNode(2));
  TreeNode* child = new TreeNode(3);
  child->children.push_back(new TreeNode(5));
  child->children.push_back(new TreeNode(6));
  root->children.push_back(child);
  child = new TreeNode(4);
  child->children.push_back(new TreeNode(7));
  root->children.push_back(child);

  print_tree(root);

  return 0;
}
}

