#include <bits/stdc++.h>

using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      //Log N to store and O(1) to get top
        priority_queue<int, vector<int>, greater<int> > pq;
    
        for(auto i : lists) {
            ListNode *aux = i;
            while(aux != NULL) {
                pq.push(aux->val);
                aux = aux->next;
            }
        }
        
        ListNode *answer = NULL;
        ListNode *head = NULL;
        
        while(!pq.empty()) {
            int current = pq.top();
            pq.pop();
            
            ListNode *aux = new ListNode();
            aux->val = current;
            
            if(answer == NULL) {    
                answer = aux;
                head = aux;
            } else {
                answer->next = aux;
                answer = aux;
            }
            
        }
        
        return head;
    }
};

int main() {

  return 0;
}