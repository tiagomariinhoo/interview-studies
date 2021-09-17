#include <bits/stdc++.h>

using namespace std;

struct MyStack {
  struct MyStack *next;
  int value;
};

MyStack * push(MyStack *stack,  int element) {
  MyStack *newElement = new MyStack;

  newElement->value = element;
  newElement->next = stack;

  return newElement;
}

void pop() {
  
}

int top() {
  return 0;
}

bool isEmpty() {

  return false;
}

int main() {
  
  MyStack *stack = new MyStack;
  stack->next = NULL;
  
  stack = push(stack, 1);
  stack = push(stack, 2);

  cout << stack->value << endl;

  return 0;
}