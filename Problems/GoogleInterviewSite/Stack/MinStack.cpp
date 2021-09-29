#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/min-stack/submissions/

class MinStack {

  struct Node{
    int value;
    int minValue;
    Node *nextNode;
  };

public:
    Node *stack;

    MinStack() {
      stack = NULL;
    }
    
    void push(int val) {
      Node *newNode = new Node();
      newNode->value = val;
      newNode->nextNode = stack;

      if(stack != NULL) {
        if(stack->minValue > val) {
          newNode->minValue = val;
        } else {
          newNode->minValue = stack->minValue;
        }
      } else {
        newNode->minValue = val;
      }

      stack = newNode;
    }
    
    void pop() {
      if(stack != NULL) {
        stack = stack->nextNode;
      }
    }
    
    int top() {
      return stack->value;
    }
    
    int getMin() {
        return stack->minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {

  MinStack stack;

  stack.push(4);
  stack.push(5);
  // stack.pop();
  cout << stack.top() << endl;
  cout << stack.getMin() << endl;

  return 0;
}