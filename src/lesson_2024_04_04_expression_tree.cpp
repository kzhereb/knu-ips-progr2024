/*
 * lesson_2024_04_04_expression_tree.cpp
 *
 *  Created on: Apr 4, 2024
 *      Author: KZ
 */


#include <string>
#include <iostream>
#include <cassert>

namespace lesson_2024_04_04_expression_tree {

enum NodeType {
  Constant,
  Variable,
  Operation
};

NodeType get_type_from_string(std::string value) {
  if(value[0]=='+' || value[0]=='-' || value[0]=='*' || value[0]=='/') {
    return Operation;
  }
  if(value[0]<='9' && value[0] >= '0') {
    return Constant;
  }
  return Variable;
}

struct TreeNode {
  std::string value;
  NodeType type;
  TreeNode* left;
  TreeNode* right;

  TreeNode(std::string value):
    value{value}, type{get_type_from_string(value)}, left{nullptr}, right{nullptr} {}
};

void print_tree(TreeNode* root) {
  assert(root!=nullptr);
  std::cout<<root->value;
  if (root->left == nullptr) {
    assert(root->right == nullptr); // either both children are present, or both children are absent
    assert(root->type != Operation); // operations must have children
    return;
  }
  std::cout<<"(";
  print_tree(root->left);
  std::cout<<" ";
  print_tree(root->right);
  std::cout<<")";
}

TreeNode* create_demo_tree() {
  TreeNode* root = new TreeNode("+");
  root->left = new TreeNode("*");
  root->left->left = new TreeNode("3");
  root->left->right = new TreeNode("-");
  root->left->right->left = new TreeNode("5");
  root->left->right->right = new TreeNode("x");
  root->right = new TreeNode("y");
  return root;

}



int main() {
  TreeNode* root = create_demo_tree();
  print_tree(root);
  return 0;
}
}
