#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    Node *next;
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
    while(head->next != NULL) {
      head = head->next;
    }

    head->next = newNode;
    head = initialHead;
  }

}

int main() {

  push_back(1);
  push_back(2);
  push_back(3);

  while(head) {
    cout << head->value << endl;
    head = head->next;
  }

  return 0;
}