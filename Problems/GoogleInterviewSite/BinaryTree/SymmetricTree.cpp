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
 * https://leetcode.com/problems/symmetric-tree/submissions/
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
    bool at = true;
    void dfs(TreeNode *leftSide, TreeNode *rightSide) {
        if(leftSide == NULL and rightSide == NULL) return ;
        
        if(leftSide != NULL and rightSide != NULL and (leftSide->val != rightSide->val)) {
            at = false;
            return ;
        } else if(leftSide == NULL || rightSide == NULL) {
            at = false;
            return;
        }
        
        dfs(leftSide->left, rightSide->right);
        dfs(leftSide->right, rightSide->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        dfs(root->left, root->right);
        return at;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}