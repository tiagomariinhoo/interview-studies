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
    /**
        Fastest solution so far
        Linear time that takes constance space

        We can solve it using a simple dfs (there's another linear solution too but takes linear auxiliary space
        u just need to store all parents and check when there's a intersection)

        But basically, u have some options:
        1 - if the current node is P or Q, u need to return true cuz u found one of them
        2 - if one of the sides of the dfs (left or right) it's true, it means that u found a node P or Q
        3 - if both of sides are true, it means that the current node, is the LCA
        4 - if one of them are true and the current node is P or Q, it means that the current node is the LCA
        5 - if one of them are true and the current node isn't P or Q, u just need to return true because one of the nodes bellow is P or Q and u need to find the LCA above the current node

    */

    bool solve(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (node == NULL) return NULL;
        
        bool a = solve(node->left, p, q);
        bool b = solve(node->right, p, q);

        if (a) {
            if (b && ans == NULL) {
                ans = node;
            } else if ((node == p || node == q) && ans == NULL) ans = node;
        } 
        
        if (b) {
            if (a && ans == NULL) {
                ans = node;
            } else if ((node == p || node == q) && ans == NULL) ans = node;
        }

        if (node == p || node == q || a || b) return true;
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        
        return ans;
    }
};