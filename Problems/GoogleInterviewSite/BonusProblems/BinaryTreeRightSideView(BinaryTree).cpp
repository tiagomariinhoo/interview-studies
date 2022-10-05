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
 * https://leetcode.com/problems/binary-tree-right-side-view/
 * 
 * Can be solved in linear time
 * 
 * Basically u just need to do a postorder dfs into the binary tree
 * storing the level for each node that u find. One thing that's good
 * to point out, is that u need to store the max level found it too,
 * to have a parameter when print all nodes.
 * 
 * This solution works because u're giving preference for the
 * rightmost node always
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
    vector<int> ans;
    int nodeLevel[1010];
    int maxLevel = 0;
	
	void dfs(TreeNode *root, int level) {
        maxLevel = max(maxLevel, level);
        
        if(root->right != NULL) {
			if(nodeLevel[level + 1] == INT_MIN) {
				nodeLevel[level + 1] = root->right->val;
			}
			dfs(root->right, level + 1);
		}
        
		if(root->left != NULL) {
			if(nodeLevel[level + 1] == INT_MIN) {
				nodeLevel[level + 1] = root->left->val;
			}
			
			dfs(root->left, level + 1);
		}
	}
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) {
			return ans;
		}
        
        // memset(nodeLevel, INT_MIN, sizeof nodeLevel);
        for(int i=0;i<=1000;i++) {
            nodeLevel[i] = INT_MIN;
        }
		
		ans.push_back(root->val);
		
		dfs(root, 0);
        
        for(int i = 1; i <= maxLevel; i++) {
            cout << i << endl;
            if(nodeLevel[i] != INT_MIN) {
                ans.push_back(nodeLevel[i]);
            }
        }
		
		return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}