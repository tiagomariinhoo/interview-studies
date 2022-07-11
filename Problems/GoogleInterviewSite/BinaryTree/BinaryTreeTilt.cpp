#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int solve(TreeNode *root) {
  if(root->left == NULL && root->right == NULL) {
    return root->val;
  }

  int leftTree = 0, rightTree = 0;

  if(root->left != NULL) {
    leftTree = solve(root->left);
  }

  if(root->right != NULL) {
    rightTree = solve(root->right);
  }

  ans += (abs(leftTree - rightTree));
  return (abs(leftTree - rightTree));
}

int findTilt(TreeNode* root) {
  if(root == NULL) return 0;
  solve(root);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  return 0;
}