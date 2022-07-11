#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/
 * 
 * It's just an easy problem that can be solved using just a dfs.
 * 
 * Just doing a dfs, u can store the current deep and check the answer
 * 
 * The problem can be solved in O(N + M) where N is the number of nodes and M is the number of edges
 */ 

int ans;

void solve(TreeNode *node, int deep) {
    if(deep > ans) ans = deep;

    if(node->left != NULL) {
        solve(node->left, deep + 1);
    }

    if(node->right != NULL) {
        solve(node->right, deep + 1);
    }
}

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    solve(root, 1);
    return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  return 0;
}