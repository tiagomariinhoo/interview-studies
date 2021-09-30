#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/partition-list/submissions/
 * 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *listAux = NULL;
        ListNode *headAux = NULL;
        
        ListNode *listAux2 = NULL;
        ListNode *headAux2 = NULL;
        
        while(head != NULL) {
            ListNode *node = new ListNode();
            node->val = head->val;
            
            if(head->val >= x) {
                if(listAux == NULL) {
                    listAux = node;
                    headAux = listAux;
                } else {
                    listAux->next = node;
                    listAux = node;
                }
            } else {
                if(listAux2 == NULL) {
                    listAux2 = node;
                    headAux2 = listAux2;
                } else {
                    listAux2->next = node;
                    listAux2 = node;
                }
            }
            
            head = head->next;
        }
        if(listAux2 != NULL) {
            listAux2->next = headAux;    
        } else headAux2 = headAux;
        
        return headAux2;
    }
};

int main() {

  return 0;
}