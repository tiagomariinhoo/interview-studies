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
 * https://leetcode.com/problems/validate-binary-search-tree/submissions/
 * 
 * To check if is a binary search tree, u need check the condition if:
 * The left subtree can't have a node that will be greater than current node
 * The right subtree can't have a node that will be less than current node
 * 
 * So you can make a dfs in order, to store the leftmost value and keep storing
 * to check if there is something wrong on both trees
 * 
 * The main point is: The left node for any node, is always less than the current node
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
    long long int aux = -LLONG_MAX;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        bool left = isValidBST(root->left);
        if(aux >= root->val) return false;
        aux = root->val;
        bool right = isValidBST(root->right);
        
        return (left && right);
    }
};

#include <bits/stdc++.h>
using namespace std;

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

bool at = true;
long long int aux = -LLONG_MAX;

/**
 * Another good property to use in BST is that if u read the elements in order
 * u can see that they will be ordered
 */ 
// bool isValidBST(TreeNode* root) {

//     bool testLeft = true, testRight = true;
//     if(root->left != NULL) {
//         if(root->left->val < root->val) {
//             testLeft = isValidBST(root->left);
//         } else {
//             testLeft = false;
//         }
//     } 
    
//     if(aux >= root->val) testLeft = false;
//     aux = root->val;

//     if(root->right != NULL) {
//         if(root->right->val > root->val) {
//             testRight = isValidBST(root->right);
//         } else {
//             testRight = false;
//         }
//     } 

    

//     return (testLeft && testRight);
// }

vector<int> ans;
void solve(TreeNode *root) {
    if(root == NULL) return true;
    if(root->left != NULL){
        solve(root->left);
    }
    ans.push_back(root->val);
    if(root->right != NULL){
        solve(root->right);
    }
}
bool isValidBST(TreeNode* root) {
    solve(root);
    for(int i=1;i<ans.size();i++) {
        if(ans[i] <= ans[i-1]) return false;
    }

    return true;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}