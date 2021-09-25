#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node *nextNode;
  int value;
};

Node *createNode() {
 Node *newNode = new Node();   
 newNode->nextNode = NULL;
 
 return newNode;
}

Node *push(Node *stack, int value) {

  Node *newNode = createNode();
  newNode->value = value;
  newNode->nextNode = stack;

  return newNode;
}

Node *pop(Node *stack) {
  if(stack != NULL) {
    stack = stack->nextNode;
    return stack;
  }

  return NULL;
}

int top(Node *stack) {
  if(stack != NULL) {
    return stack->value;
  }
  return -INT_MAX;
}

bool isEmpty(Node *stack) {
  if(stack == NULL) return true;

  return false;
}

int main() {

  Node *stack = NULL;

  stack = push(stack, 2);
  stack = push(stack, 3);

  cout << top(stack) << endl;


  return 0;
}