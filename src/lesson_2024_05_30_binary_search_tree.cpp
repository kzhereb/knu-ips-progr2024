/*
 * lesson_2024_05_30_binary_search_tree.cpp
 *
 *  Created on: May 30, 2024
 *      Author: KZ
 */

#include <iostream>
#include <cassert>


namespace lesson_2024_05_30_binary_search_tree {

struct TreeNode {
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr):
    value(value), left(left), right(right) {}
};

TreeNode* find_max_node(TreeNode* root) {
  assert(root != nullptr);
  TreeNode* current = root;
  while (current->right != nullptr) {
    current = current->right;
  }
  return current;
}


TreeNode* merge_separated(TreeNode* less_root, TreeNode* greater_equal_root) {
  if (less_root == nullptr) {
    return greater_equal_root;
  }
  TreeNode* max_less = find_max_node(less_root);
  assert(max_less->right == nullptr);
  max_less->right = greater_equal_root;
  return less_root;
}

void add_item(TreeNode*& root, int value) {
  if (root == nullptr) {
    root = new TreeNode(value);
    return;
  }
  if (root->value > value) {
    add_item(root->left, value);
  } else {
    add_item(root->right, value);
  }
}

void print_tree(TreeNode* root) {
  if(root==nullptr) {
    std::cout<<"_";
    return;
  }
  std::cout<<root->value;
  if (root->left == nullptr && root->right == nullptr) { return; } // don't output (_ _)
  std::cout<<"(";
  print_tree(root->left);
  std::cout<<" ";
  print_tree(root->right);
  std::cout<<")";
}

void print_sequence(TreeNode* root) {
  if(root == nullptr) { return;}
  print_sequence(root->left);
  if (root->left) {std::cout<<" ";}
  std::cout<<root->value;
  if (root->right) {
    std::cout<<" ";
    print_sequence(root->right);
  }
}

void print_all(TreeNode* root) {
  print_tree(root);
  std::cout<<" => ";
  print_sequence(root);
  std::cout<<std::endl;
}


int main() {
  TreeNode* less_root = new TreeNode(1);
  add_item(less_root, 0);
  add_item(less_root, 2);
  print_all(less_root);
  //std::cout<<std::endl;

  TreeNode* greater_root = new TreeNode(5);
  add_item(greater_root, 4);
  add_item(greater_root, 7);
  print_all(greater_root);
  //std::cout<<std::endl;

  TreeNode* merged = merge_separated(less_root, greater_root);
  print_all(merged);
  //std::cout<<std::endl;



  return 0;
}
}


