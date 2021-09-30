#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/linked-list-cycle/submissions/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while(head != NULL) {
            
            if(head->next && head->next->val == INT_MAX) {
                return true;
            }
            head->val = INT_MAX;
            head = head->next;
        }
        
        return false;
    }
};
int main() {

  return 0;
}