/*
 * lesson_2024_04_04_expression_tree.cpp
 *
 *  Created on: Apr 4, 2024
 *      Author: KZ
 */


#include <string>
#include <iostream>
#include <map>
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

double calculate_value(TreeNode* root, std::map<std::string, int> variable_values) {
  assert(root!=nullptr);
  if (root->type == Operation) {
    double left_value = calculate_value(root->left, variable_values);
    double right_value = calculate_value(root->right, variable_values);
    if (root->value == "+") { return left_value + right_value;}
    if (root->value == "-") { return left_value - right_value;}
    if (root->value == "*") { return left_value * right_value;}
    if (root->value == "/") { return left_value / right_value;}
  }
  if (root->type == Constant) {
    return std::stod(root->value); // converts string to double
  }
  if (root->type == Variable) {
    return variable_values[root->value];
  }
  assert(false); // should not reach this
}



int main() {
  TreeNode* root = create_demo_tree();
  print_tree(root);
  std::cout<<std::endl;

  double result = calculate_value(root, { {"x", 2}, {"y", 1} });
  std::cout<<"value of expression is "<<result<<std::endl;

  return 0;
}
}
