#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/diameter-of-binary-tree/submissions/
 * 
 * This problem can be solved in O(N + M) just doing a dfs
 * 
 * For each node, just need to count the quantity of nodes in each
 * subtree (left and right) and update the max answer
 * 
 * This works because starting from a node, the sum of the
 * depth of each subtree will be the answer, since to
 * go to the deppest node in each subtree, u need to pass
 * through the common ancestor
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
    int ans = 0;
    int dfs(TreeNode *node, int currentDist) {
        if(node->left == NULL && node->right == NULL) {
            return 0;    
        }
        
        int leftDist = 0, rightDist = 0;
        
        if(node->left != NULL) {
            leftDist = dfs(node->left, currentDist + 1) + 1;
        }    
        
        if(node->right != NULL) {
            rightDist = dfs(node->right, currentDist + 1) + 1;
        }    
        
        ans = max(ans, leftDist + rightDist);
        
        return max(leftDist, rightDist);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}