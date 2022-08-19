#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/clone-graph/
 * 
 * We can make a clone just using a dfs, then
 * the solution runs in: O(N + M)
 * 
 * The thing here is that for some reason, the
 * leetcode was not recognizing the cloned graph
 * when the elements comes from: new Node(node->val, node->neighbors)
 * in a different pointer
 * 
 * Then here, the solution was kinda change the current node for another
 * one and return it
 * 
 * For each node, I just need to new Node = (val, neighbors)
 * and the current vis[node] will be the newNode
 * 
 * After that, just do the normal dfs using the own function
 * passing the current node from newNode
 */ 

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> vis;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        if(vis[node]) return vis[node];
        
        Node *newNode = new Node(node->val, node->neighbors);
        vis[node] = newNode;
        
        for(auto &currentNode : newNode->neighbors) {
            currentNode = cloneGraph(currentNode);
        }
        
        return newNode;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}