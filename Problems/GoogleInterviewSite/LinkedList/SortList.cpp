#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sort-list/submissions/
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
    ListNode* sortList(ListNode* head) {
        vector<int> vec;
        
        while(head != NULL) {
            vec.push_back(head->val);
            head = head->next;
        }
        
        sort(vec.begin(), vec.end());
        
        ListNode *sortedList = NULL;
        ListNode *headAux = NULL;
        
        for(auto i : vec) {
            ListNode *node = new ListNode();
            node->val = i;
            if(sortedList == NULL) {    
                sortedList = node;
                headAux = node;
            } else {
                sortedList->next = node;
                sortedList = node;
            }
        }
        
        return headAux;
    }
};

int main() {

  return 0;
}