#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(1e5 + 5)
#define MAXL 20
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 9)
#define MOD2 (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, lli> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

/**
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
 * 
 * This can be solved in linear time
 * 
 * You just need to see that if u do a dfs in order in a BST
 * If its a really BST, the sequence will be:
 * 1 2 3 4 5... so u just need to store a count and if count == k, u get the answer
 * 
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
    int count = 0;
    int ans = 0;
    
    void dfs(TreeNode *root, int k) {
        if(root == NULL) return ;
        dfs(root->left, k);
        count++;
        if(count == k) ans = root->val;
        dfs(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}