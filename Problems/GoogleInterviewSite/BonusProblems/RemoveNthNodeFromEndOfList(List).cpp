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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *aux = head;
        while(aux != NULL) {
            count ++;
            aux = aux->next;
        }
        
        if(count == n) {
            head = head->next;
        } else if(n == 1) {
            aux = head;
            while(1) {
                if(count == 2) {
                    aux->next = NULL;
                    break;
                }
                
                aux = aux->next;
                count--;
            }
        } else {
            aux = head;
            while(1) {
                if(count == n + 1) {
                    aux->next = aux->next->next;
                    break;
                }
                
                count--;
                aux = aux->next;
            }
        }
        
        return head;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}