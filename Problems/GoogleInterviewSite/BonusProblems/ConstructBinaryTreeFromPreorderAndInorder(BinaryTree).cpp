#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/
 * 
 * It's a hard problem.
 * An important thing is that preorder, the first element will be root
 * When the preorder element is equal inorder element, u need to know 
 * if u can go to the parent or go to the right
 * 
 * If the inorder element was already visited, just go up
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
    vector<int> globalPreorder;
    vector<int> globalInorder;
    int idxPreorder;
    int idxInorder;
    TreeNode *head = NULL;
    
    TreeNode* createNode(int val) {
        TreeNode *newNode = new TreeNode();
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->val = val;
        
        return newNode;
    }
    
    unordered_map<int, int> vis;
    
    TreeNode* dfs(TreeNode *node) {
        if(idxPreorder >= globalPreorder.size() ||
          idxInorder >= globalInorder.size()) return node;
        
         if(idxInorder < globalInorder.size()) {
                if(vis[globalInorder[idxInorder]]) return node;
        }
        
        if(node == NULL) {
            node = createNode(globalPreorder[idxPreorder]);
            vis[node->val] = 1;
            if(head == NULL) head = node;
        }
        
        
        if(globalInorder[idxInorder] == node->val) {
            idxInorder++;
            if(idxInorder < globalInorder.size()) {
                if(vis[globalInorder[idxInorder]]) return node;
            }
            idxPreorder++;
            node->right = dfs(node->right);
        } else {
            idxPreorder++;
            node->left = dfs(node->left);
             idxInorder++;
            if(idxInorder < globalInorder.size() && vis[globalInorder[idxInorder]]) {
                return node;
            }
            idxPreorder++;
            node->right = dfs(node->right);
        }
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        
        globalPreorder = preorder;
        globalInorder = inorder;
        
        
        return dfs(NULL);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}