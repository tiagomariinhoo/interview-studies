#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/
 * 
 * It's possible to find the answer in Log N, since is a Binary Search Tree
 * 
 * For each node, u just need to check if the current node
 * is >=e p and <= q, that's will be the LCA
 * 
 * If not, u just need to go to the correct side according
 * the value, if both are smaller, go left, otherwise, go right
 * 
 */ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans = NULL;
    
    int leftNode = 0;
    int rightNode = 0;
    
    void dfs(TreeNode *node) {
        if(ans != NULL) {
            return ;
        }
        
        if(node->left != NULL && node->right != NULL) {
            if(leftNode < node->val && rightNode < node->val) {
                dfs(node->left);
            } else if(leftNode > node->val && rightNode > node->val) {
                dfs(node->right);
            } else if(leftNode <= node->val && rightNode >= node->val) {
                ans = node;
                return;
            }
        } else {
            cout << node->val << endl;
            ans = node;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        leftNode = p->val;
        rightNode = q->val;
        if(leftNode > rightNode) swap(leftNode, rightNode);
        
        dfs(root);
        
        return ans;
    }
};
    

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}