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
 * https://leetcode.com/problems/merge-two-binary-trees/submissions/
 * 
 * Can be solved in linear time, just using the own function
 * to do the recursion and update each node
 * 
 * Check if there's left or right node and update the current value
 * go through the left or right node and do the same
 * 
 * Constant auxiliary space too
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
    
    TreeNode *createNode(int val, int val2) {
        TreeNode *newNode = new TreeNode(val + val2);
        newNode->left = NULL;
        newNode->right = NULL;
        
        return newNode;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        int a = 0, b = 0;
        if(root1 != NULL) a = root1->val;
        if(root2 != NULL) b = root2->val;
        
        TreeNode *newNode = createNode(a, b);
        if(root1 != NULL && root2 != NULL) {
            newNode->left  = mergeTrees(root1->left, root2->left);
            newNode->right  = mergeTrees(root1->right, root2->right);   
        } else if(root1 != NULL) {
            newNode->left  = mergeTrees(root1->left, NULL);
            newNode->right  = mergeTrees(root1->right, NULL);   
        } else if(root2 != NULL) {
            newNode->left  = mergeTrees(root2->left, NULL);
            newNode->right  = mergeTrees(root2->right, NULL);   
        } else return NULL;
        
        return newNode;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}