/*
 * lesson_2024_05_23_expression_postfix.cpp
 *
 *  Created on: May 23, 2024
 *      Author: KZ
 */

#include <iostream>
#include <string>
#include <stack>
#include <cassert>

namespace lesson_2024_05_23_expression_postfix {

std::string infix_to_postfix(std::string expression) {
  std::string result;
  std::stack<char> operator_stack;

  for (char current: expression) {
    if (current <= '9' && current >= '0') {
      result += current;
    } else if (current == '-') {
      while (!operator_stack.empty()) {
        char from_stack = operator_stack.top();
        if (from_stack == '-') { // left associative
          operator_stack.pop();
          result += from_stack;
        } else if (from_stack == '/') { // greater precedence
          operator_stack.pop();
          result += from_stack;
        } else if (from_stack == '(') {
          break; // no more operators for result
        }
      } // while there are suitable operators on stack
      operator_stack.push(current);
    } else if (current == '/') {
      while (!operator_stack.empty()) {
        char from_stack = operator_stack.top();
        if (from_stack == '-') { // less precedence
          break;
        } else if (from_stack == '/') { // left associative
          operator_stack.pop();
          result += from_stack;
        } else if (from_stack == '(') {
          break; // no more operators for result
        }
      } // while there are suitable operators on stack
      operator_stack.push(current);
    } else if (current == '(') {
      operator_stack.push(current);
    } else if (current == ')') {
      while (!operator_stack.empty()) {
        char from_stack = operator_stack.top();
        if (from_stack != '(') {
          operator_stack.pop();
          result += from_stack;
        } else {
          break;
        }
      } // while operator on stack is not (
      if (operator_stack.empty()) {
        return "error: ')' without '('";
      }
      assert(operator_stack.top() == '(');
      operator_stack.pop(); // discard matching (
    } // if current
  } // for current: input

  while(!operator_stack.empty()) {
    char from_stack = operator_stack.top();
    if (from_stack == '(') {
      return "error: '(' without ')'";
    }
    operator_stack.pop();
    result += from_stack;
  }

  return result;
}

void check_expression(std::string expression) {
  std::cout<<expression<<" => "<< infix_to_postfix(expression)<<std::endl;
}

int main() {
  // 1-2-3   -> 1 2 - 3 -
  // 1-(2-3) -> 1 2 3 - -
  // 1/2-3   -> 1 2 / 3 -
  // 1/2/3   -> 1 2 / 3 /
  // 1-2/3   -> 1 2 3 / -
  // )       -> error
  // (       -> error
  check_expression("1-2-3");
  check_expression("1-(2-3)");
  check_expression("1/2-3");
  check_expression("1/2/3");
  check_expression("1-2/3");
  check_expression(")");
  check_expression("(");


  return 0;
}
}


