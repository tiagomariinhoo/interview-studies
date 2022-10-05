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
 * https://leetcode.com/problems/longest-increasing-subsequence-ii/
 * 
 * Solution: https://leetcode.com/problems/longest-increasing-subsequence-ii/discuss/2560010/C%2B%2B-Segment-tree-with-illustrationexplanation
 * 
 * Interesting problem. Basically u need to find a LIS where the gap
 * between the numbers has to be <= k
 * 
 * The solution runs in N Log N and can be solved using a Segment Tree
 * 
 * The only difference is that here, u'll use the element and the Tree Size
 * will be 4*MaxElement in array
 * 
 * So, let's use the first case as an example to explain the solution:
 * [4, 2, 1, 4, 3, 4, 5, 8, 15], k = 3
 * 
 * U need to find a LIS where the gap is <= 3, so the answer would be:
 * [1, 3, 4, 5, 8]
 * 
 * Our current tree: 0, 0, 0, 0, 0, ... 0
 * Basically using a SegTree u can keep looping through the array and do the following:
 * 4 - first element, let's get the max list from (element - k, element - 1)
 * Query = 0, let's update 4 with 1, the current Lis here is 1
 * 
 * 2 - second element, 1 too becuase there is no LIS before this number
 * 
 * 1 - third element, 1 too because there is no LIS before this number
 * 
 * 4 - fourth element, here, when we find for the max query between [1, 3], we can find 1, since they were already updated with 1
 * Then the answer here will be query(1, 3) + 1 (including this element on LIS)
 * Then the answer here will be 2, just keep doing it and updating the max answer
 */

class Solution {
public:
    int tree[400011];
    int vec[100001];
    
//     void build(int node, int start, int end) {
//         if(start == end) {
//             tree[node] = vec[start];
//             return ;
//         }
        
//         int mid = (start + end) / 2;
//         build(2*node, start, mid);
//         build(2*node + 1, mid + 1, end);
//         tree[node] = max(tree[2*node], tree[2*node + 1]);
//     }
    
    int query(int l, int r, int node, int start, int end) {
        if(start > r or end < l) return 0;
        else if(start >= l && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        int a = query(l, r, 2*node, start, mid);
        int b = query(l, r, 2*node + 1, mid + 1, end);
        
        return max(a, b);
    }
    
    void update(int pos, int val, int node, int start, int end) {
        if(start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if(start <= pos && pos <= mid) update(pos, val, 2*node, start, mid);
            else update(pos, val, 2*node+1, mid+1, end);
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            vec[i+1] = nums[i];
        }
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++) {
            int current = query(max(vec[i] - k, 1), vec[i] - 1, 1, 1, 100000);
            update(vec[i], current + 1, 1, 1, 100000);
            
            ans = max(ans, current + 1);
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}