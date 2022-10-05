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
 * https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
 * 
 * Storing a parente for each node, it's possible make something like a bidirectional graph
 * 
 * So now, I just need to do a dfs storing visited nodes and get the max distance
 * 
 * Linear complexity time and auxiliary space
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
    unordered_map<TreeNode*, int> vis;
    unordered_map<TreeNode*, TreeNode*> parent;
    
    TreeNode *target;
    
    void getParent(TreeNode *node, TreeNode *parentNode, int start) {
        if(node == NULL) return ;
        parent[node] = parentNode;
        
        if(node->val == start) target = node;
        
        getParent(node->left, node, start);
        getParent(node->right, node, start);
    }
    
    int ans = 0;
    
    int dfs(TreeNode *node, int distance) {
        if(node == NULL) return 0;
        if(vis[node]) return 0;
        vis[node] = 1;
        
        ans = max(ans, distance);
        
        int a = dfs(node->left, distance + 1);
        int b = dfs(node->right, distance + 1);
        int c = dfs(parent[node], distance + 1);
        
        return ans;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        getParent(root, NULL, start);
        dfs(target, 0);
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}