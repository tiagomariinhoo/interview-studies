#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
 * 
 * Just be careful with the corner cases:
 * 
 * Begin of the list
 * End of the list
 * Middle of the list
 * 
 * Can be solved in linear time
 */ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /**
        There are three situations here:
        - Remove from beginning
        - Remove from middle 
        - Remove from end
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *aux = head;
        while (aux != NULL) {
            count++;
            aux = aux->next;
        }

        aux = head;
        ListNode *prev = NULL;

        while (aux != NULL) {
            if (count == n) {
                if (prev != NULL) {
                    prev->next = aux->next;
                } else {
                    head = head->next;
                }
            }

            prev = aux;
            aux = aux->next;
            count--;
            if (count < 0) break;
        }

        return head;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}