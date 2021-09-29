#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/merge-two-sorted-lists/submissions/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *mergedList = NULL;
        ListNode *head = NULL;

        while(l1 != NULL or l2 != NULL) {
          ListNode *smallestNode = new ListNode();
          smallestNode->val = INT_MAX;

          if(l1 != NULL) {
            smallestNode->val = l1->val;
          }

          

          if(l2 != NULL && smallestNode->val >= l2->val) {
              smallestNode->val = l2->val;
              l2 = l2->next;
            } else {
              l1 = l1->next;
            }

          if(mergedList == NULL) {
            mergedList = smallestNode;
            head = mergedList;
          } else {
            mergedList->next = smallestNode;
            mergedList = smallestNode;
          }
        }

        return head;
    }
};

int main() {

  return 0;
}