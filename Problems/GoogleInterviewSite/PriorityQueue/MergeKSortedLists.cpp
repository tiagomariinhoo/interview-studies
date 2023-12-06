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

// DIVIDE AND CONQUER SOLUTION N LOG N O(1) SPACE
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

    // We need to merge the lists recursively
    // Merge all nodes between two lists
    ListNode *mergeSort(ListNode *a, ListNode *b) {
        if (a == NULL) return b;
        else if (b == NULL) return a;

        ListNode *aux;

        if (a->val <= b->val) {
            aux = a;
            a->next = mergeSort(a->next, b);
        } else {
            aux = b;
            b->next = mergeSort(a, b->next);
        }

        return aux;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        // When we're merging the lists, we will reduce the lists.size() using this pointer
        int last = lists.size() - 1;

        // Repeat it until only one list is left
        while (last != 0) {
            int i = 0, j = last;
            // We can reduce the pairs
            while(i < j) {
                // Merge list j with list i
                lists[i] = mergeSort(lists[i], lists[j]);
                // consider the next pait
                i++, j--;
                // if all pairs are merged, update last
                if (i >= j) last = j;
            }
        }

        return lists[0];
    }
};