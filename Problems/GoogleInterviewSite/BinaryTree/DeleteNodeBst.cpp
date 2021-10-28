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
 * https://leetcode.com/problems/delete-node-in-a-bst/submissions/
 * 
 * The points are:
 * 1 - We can find the node that we want to remove, in O (log n), since our tree is a BST, we can just keep following the tree value and check if my current valye is greater or less than my key
 * 2 - We have 4 situations when found our node: Left child null, right child null, both null and both not null
 * 2.1 - If left child or right child are null, we just need get the child that is not null and replace
 * 2.2 - If both children are null, we just need to delete the node
 * 2.3 - If both children are not null, we need to get the right children, leftmost node, that will be the next node that we should have in order.
 *      For this, I need to get him and replace my current node, after this, I just need to remove him, replacing my current key
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
    
    TreeNode *findMin(TreeNode* node) {
        while(node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if(root->left == NULL and root->right == NULL) {
                root = NULL;
                return NULL;
            } else if(root->left == NULL) {
                root = root->right;
                return root;
            } else if(root->right == NULL) {
                root = root->left;
                return root;
            } else {
                TreeNode *aux = findMin(root->right);
                root->val = aux->val;
                root->right = deleteNode(root->right, aux->val);
            }
        }
        
        return root;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}