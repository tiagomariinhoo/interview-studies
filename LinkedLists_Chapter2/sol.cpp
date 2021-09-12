#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    Node *next;
    Node *prev;
    int value;
};

Node *head = NULL;

void push_back(int v) {

  Node *newNode = new Node;
  newNode->next = NULL;
  newNode->value = v;

  if(head == NULL) {
    head = newNode;
  } else {
    Node *initialHead = head;
    Node *previousNode = NULL;
    while(head->next != NULL) {
      head = head->next;
      previousNode = head;
    }

    head->next = newNode;
    head->prev = previousNode;
    head = initialHead;
  }

}

void firstSolution() {
  
  set<int> nums;

  Node *initialPosition = head;
  while(head) {
    nums.insert(head->value);
    head = head->next;
  }

  // for(auto i : nums) cout << i << endl;
  head = NULL;

  for(auto i : nums) {
    push_back(i);
  }

  while(head) {
    cout << head->value << endl;
    head = head->next;
  }

  /**
   * To solve this without a temporary buffer,
   * just use an quadratic soluton
   */
}

Node *head2 = NULL;

void secondSolution() {
  unordered_set<Node*> nodes;
}

int main() {

  // push_back(1);
  // push_back(2);
  // push_back(3);

  // while(head) {
  //   cout << head->value << endl;
  //   head = head->next;
  // }

  // push_back(1);
  // push_back(2);
  // push_back(3);
  // push_back(3);
  // push_back(4);

  /**
   * First problem
   * 
   * Remove duplicates from an unsorted linked list
   */ 
  firstSolution();

  /**
   * Second problem
   * 
   * Check if the linked list is a palindrome
   */ 

  push_back(1);
  push_back(2);
  push_back(2);
  push_back(1);
  secondSolution();

  return 0;
}