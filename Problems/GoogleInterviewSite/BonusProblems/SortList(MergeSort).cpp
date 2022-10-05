#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/sort-list/
 * 
 * Good problem for practice MergeSort
 * 
 * Runs in NLogN
 */

class Solution {
public:
    
    int n;
    void getSize(ListNode *head) {
        ListNode *aux = head;
        int count = 0;
        while(aux != NULL) {
            count++;
            aux = aux->next;
        }
        
        n = count;
    }
    
    
    void printList(ListNode *head) {
        ListNode *aux = head;
        while(aux != NULL) {
            cout << aux->val << " ";
            aux = aux->next;
        } cout << endl;
    }
    
    ListNode *mergeLists(ListNode *node, ListNode *node2) {
        ListNode *head = NULL;
        ListNode *aux = NULL;
            
        if(node->val <= node2->val) {
            head = node;
            node = node->next;
        } else {
            head = node2;
            node2 = node2->next;
        }
        
        aux = head;
            
        while(node != NULL || node2 != NULL) {
            if(node != NULL && node2 != NULL) {
                if(node->val <= node2->val) {
                    aux->next = node;
                    node = node->next;
                } else {
                    aux->next = node2;
                    node2 = node2->next;
                }
            } else if(node != NULL) {
                aux->next = node;
                node = node->next;
            } else {
                aux->next = node2;
                node2 = node2->next;
            }
            aux = aux->next;
        }
        
        return head;
    }
    
    ListNode *mergeSort(ListNode *node, int currentSize) {
        if(currentSize == 1) {
            return node;
        }
        
        ListNode *firstPartition = node;
        ListNode *secondPartition = NULL;
        
        int nn = currentSize / 2;
        int mm = (currentSize % 2 == 0 ? currentSize / 2 : (currentSize / 2) + 1);
        
        for(int i = 0; i < nn; i ++) {
            if(i == nn - 1) {
                secondPartition = node->next;
                node->next = NULL;
            }
            node = node->next;
        }
        
        ListNode *a = mergeSort(firstPartition, nn);
        ListNode *b = mergeSort(secondPartition, mm);
        
        ListNode *mergedList = mergeLists(a, b);
        
        return mergedList;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        
        getSize(head);
        
        return mergeSort(head, n);
    }
};

int main() {

  return 0;
}