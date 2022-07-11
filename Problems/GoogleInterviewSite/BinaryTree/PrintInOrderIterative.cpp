#include <bits/stdc++.h>
using namespace std;
/**
 * https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/
 * 
 * It's a interesting problem. Basically you just need to imagine how will be
 * the dfs using Stack (usually iterative Dfs is solved using stack and
 * Bfs is solved using queue). The only thing to think is that u need to store
 * the "node back", in other words, you can put the current node into the stack
 * again but with a flag saying that he's returning to the stack again, when do it
 * just put into the Answer vector
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
      vector<int> ans;
    map<int,int> vis;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return ans;
        
        // stack<TreeNode*> st;
        stack<pair<TreeNode*, int> > st;
        st.push({root, 0});
        
        while(!st.empty()) {
            // TreeNode *topElement = st.top();
            pair<TreeNode*, int> topElement = st.top();
            st.pop();
            
            if(topElement.second == 1 || topElement.first->right == NULL && topElement.first->left == NULL) {
                ans.push_back(topElement.first->val);
                continue;
            } 
            // vis[topElement->val] = 1;
            // ans.push_back(topElement->val);
            
            
            
            
            if(topElement.first->right != NULL) {
                st.push({topElement.first->right, 0});
            }
            
            st.push({topElement.first, 1});
            
            if(topElement.first->left != NULL) {
                st.push({topElement.first->left, 0});
            }  
        }
        
        
        return ans;
    }
};

int main() {

}