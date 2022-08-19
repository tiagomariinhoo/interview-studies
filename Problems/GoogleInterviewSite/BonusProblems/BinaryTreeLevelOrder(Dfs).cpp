#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/
 * 
 * Very easy problem, just using a dfs
 * Just store the level for each node
 * 
 * The problem can be solved in O(N + M) like a normal dfs
 * 
 * Where N is the number of nodes and M the number of edges
 */ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> vec[2001];
    
    void dfs(TreeNode *node, int level) {
        if(node == NULL) return;
        vec[level].push_back(node->val);
        
        if(node->left) {
            dfs(node->left, level + 1);
        }
        
        if(node->right) {
            dfs(node->right, level + 1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;
            
        dfs(root, 0);
        for(int i = 0; i <= 2000; i++) {
            if(vec[i].size() > 0) {
                ans.push_back(vec[i]);
            }
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}