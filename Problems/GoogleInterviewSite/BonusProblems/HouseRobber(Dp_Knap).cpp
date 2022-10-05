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
 * https://leetcode.com/problems/house-robber/submissions/
 * 
 * Easy knapsack-based problem, just do the same as knap
 * using dynamic programming
 * 
 * Can be solved in linear time and linear space 
 */

class Solution {
public:
    
    vector<int> vec;
    int memo[101];
    
    int solve(int pos) {
        if(pos >= vec.size()) return 0;
        if(memo[pos] != -1) return memo[pos];
        
        int a = max({
            solve(pos + 2) + vec[pos],
            solve(pos + 1)
        });
        
        return memo[pos] = a;
    }
    
    int rob(vector<int>& nums) {
        vec = nums;
        
        memset(memo, -1, sizeof memo);
        
        return solve(0);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}