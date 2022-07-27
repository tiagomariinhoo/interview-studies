#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/
 * 
 * Basically for each node, you just need to fill the Next pointer for the right node at the same level.
 * 
 * The solution was using a map that store the last left node and using a dfs from the left to right, I just
 * need to get the last left node from each node and fill the next pointer.
 * 
 * The solution runs in O((N + M) * log N) as a normal Dfs 
 */ 

class Solution {
public:
    Node* globalRoot;
    
    map<int, Node*> lastNodeFromLeft;
    
    void dfs(Node *node, int level) {
        if(node == NULL) return;
        
        if(lastNodeFromLeft[level] != NULL) {
            lastNodeFromLeft[level]->next = node;
            lastNodeFromLeft[level] = node;
        } else {
            lastNodeFromLeft[level] = node;
        }
        
        if(node->left != NULL) {    
            dfs(node->left, level + 1);
        }
        
        if(node->right != NULL) {    
            dfs(node->right, level + 1);
        }
    }
    
    Node* connect(Node* root) {
        globalRoot = root;
        dfs(root, 0);
        
        return globalRoot;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}