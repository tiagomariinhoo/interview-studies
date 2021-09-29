#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL or node->next == NULL) {
          return ;
        }

        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {

  return 0;
}