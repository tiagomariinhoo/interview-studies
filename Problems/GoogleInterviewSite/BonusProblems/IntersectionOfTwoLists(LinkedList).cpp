#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/
 * 
 * Just store the visited nodes in a map
 * Linear space 
 * Linear time
 */ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *auxA = headA;
        
        map<ListNode *, int> vis;
        
        ListNode *auxB = headB;
        
        while(auxA != NULL) {
            vis[auxA] = 1;
            auxA = auxA->next;
        }
        
        while(auxB != NULL) {
            if(vis[auxB]) return auxB;
            auxB = auxB->next;
        }
        
        return NULL;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}