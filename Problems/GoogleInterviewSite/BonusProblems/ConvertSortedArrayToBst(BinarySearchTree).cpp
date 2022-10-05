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
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/
 * 
 * Isn't a so easy problem, but can be solved in linear time using
 * the merge sort idea.
 * It's possible to see that if we can keep spliting the array
 * in two partitions, we can build a high balanced tree
 * (use [0,1,2,3,4,5] as an example and use the tree visualizer) 
 * u can see that the middle is 3, and u can split [0, 1, 2] and [4, 5]
 * and keep doing the same for each side
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
    
    TreeNode *createNode(int val) {
        TreeNode *newNode = new TreeNode(val);
        newNode->left = NULL;
        newNode->right = NULL;
        
        return newNode;
    }
    
    vector<int> vec;
    TreeNode *root;
    
    
    TreeNode *solve(int l, int r) {
        if(l == r) {
            return createNode(vec[l]);
        } else if(l > r) return NULL;
        
        int mid = (l + r) / 2;
        TreeNode *newNode = createNode(vec[mid]);
        newNode->left = solve(l, mid - 1);
        newNode->right = solve(mid + 1, r);
        
        return newNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        vec = nums;
        // *root = createNode(nums[nums.size() / 2]);
        
        solve(0, nums.size() - 1);
        
        return solve(0, nums.size() - 1);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}