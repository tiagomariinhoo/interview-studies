#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/palindrome-linked-list/
 * 
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

//O(N) Solution with O(N) Space
/**
 * Just using stack and comparing passing through the list
 * and popping the stack
 */ 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        
        ListNode *aux = head;
        
        while(aux != NULL) {
            st.push(aux->val);
            aux = aux->next;
        }
        
        aux = head;
        while(!st.empty() && aux != NULL) {
            if(st.top() != aux->val) return false;
            st.pop();
            
            aux = aux->next;
        }
        
        return true;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}