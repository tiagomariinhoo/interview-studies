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
    /**
        Suggestions for next problems: Sum Root to Leaf Numbers and Path Sum IV

        This problem can be solved in N + M (dfs complexity)
        And basically we have some options:
        1 - Return just the current Node->val
        2 - Return the left path + current node-val
        3 - Return the right path + current node->val
        4 - Get the Left + Right path + current node-val

        The steps 1, 2 and 3 we can return them because it can make another path using the parent
        The step 4 is just a situation where we want to get the best path from left and right at the same time

        That's the kind of problem that is good to draw all those situations for a better understanding
    */
    int ans = -INT_MAX;

    int dfs(TreeNode *node) {
        if (node == NULL) return 0;

        int l = dfs(node->left);
        int r = dfs(node->right);
        int ownPath = (l + r + node->val);
        ans = max({ownPath, node->val, node->val + l, node->val + r, ans});


        return max({node->val, l + node->val, r + node->val});
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);

        return ans;
    }
};