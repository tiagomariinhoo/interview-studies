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
 * https://leetcode.com/problems/longest-increasing-subsequence/
 * 
 * Solution variation: https://leetcode.com/problems/longest-increasing-subsequence-ii/discuss/2560010/C%2B%2B-Segment-tree-with-illustrationexplanation
 * 
 * Classical problem to find LIS
 * Usually this can be solved using Dp in n² but this solution using Seg Tree
 * Can run in N log N where N is the max number
 * There are some optimizations that we can do, like make a map into the numbers, like:
 * [100, 200, 300] can turn into -> [1, 2, 3], basically
 * 
 * For this problem, the array can contain also negative numbers, só I just sum -1e4 + 1 in every number to deal with them always >= 1
 * 
 * Then the solution is pretty straight forward, just keep looping through the array and get the max current LIS into the prefix
 * 
 * Note: What we will update in the seg tree is the number that we already have, for example:
 * [4, 2, 3, 1, 4]
 * Lis - [0, 0, 0 , 0, 0]
 * 
 * [*, 2, 3, 1, 4]
 * Lis - [0, 0, 0 , 1, 0]
 * [*, *, 3, 1, 4]
 * Lis - [0, 1, 0 , 1, 0]
 * [*, *, *, 1, 4]
 * Lis - [0, 1, 1 , 1, 0]
 * [*, *, *, *, 4]
 * Lis - [1, 1, 1 , 1, 0]
 * [*, *, *, *, *]
 * Lis - [1, 1, 1 , 2, 0] here the position 4 goes to 2 because the max lis in the prefix is 1 (1, 2 or 3)
 * 
 * This runs in N Log N Complexity time and Linear auxiliar space
 */

class Solution {
public:
    int tree[400010];
    int n;
    
    int query(int l, int r, int node = 1, int start = 1, int end = 40010) {
        if(end < l or start > r) return 0;
        if(start >=l and end <= r) return tree[node];
        
        int mid = (start + end) >> 1;
        int a = query(l, r, 2*node, start, mid);
        int b = query(l, r, 2*node + 1, mid + 1, end);
        
        return max(a, b);
    }
    
    void update(int pos, int val, int node = 1, int start = 1, int end = 40010) {
        if(start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) >> 1;
            if(start <= pos && pos <= mid) update(pos, val, 2*node, start, mid);
            else update(pos, val, 2*node + 1, mid + 1, end);
            tree[node] = max(tree[2*node], tree[2*node + 1]);
        }
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        for(auto &i : nums) i += 10001;
        
        for(auto i : nums) {
            int current = query(1, i - 1);
            ans = max(ans, current + 1);
            update(i, current + 1);
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}