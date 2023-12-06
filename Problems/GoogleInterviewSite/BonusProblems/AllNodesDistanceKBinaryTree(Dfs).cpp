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

    /**
     * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
        Storing the parent for each node
        We just need to run a dfs starting from the target node and 
        get all the nodes with distance K

        The complexity time is O(N) and O(N) Memory Space
    */

    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> ans;

    void dfs(TreeNode *node, TreeNode *p) {
        if (node == NULL) return ;
        parent[node] = p;

        dfs(node->left, node);
        dfs(node->right, node);
    }

    void solve(TreeNode *node, int dist, int k, TreeNode *last) {
        if (node == NULL) return;
        if (dist == k) {
            ans.push_back(node->val);
            return ;
        }

        if (node->left != last)
            solve(node->left, dist + 1, k, node);
        if (node->right != last)
        solve(node->right, dist + 1, k, node);
        if (parent[node] != last)
        solve(parent[node], dist + 1, k, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, NULL);
        solve(target, 0, k, NULL);
        return ans;
    }
};