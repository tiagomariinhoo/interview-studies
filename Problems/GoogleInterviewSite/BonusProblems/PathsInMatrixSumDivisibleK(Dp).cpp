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
 * https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/submissions/
 * LeetCode Contest Weekly 314
 * 
 * That's a really fun and interesting problem. Basically u just need to reach the position n-1,m-1
 * such as the sum until there, should be divisible by K and the only movements that u can is
 * down and right.
 * 
 * Basically it's a classical dp problem but the point here is that the constraints are:
 *  m == grid.length
    n == grid[i].length
    1 <= m, n <= 5 * 10^4
    1 <= m * n <= 5 * 10^4
    0 <= grid[i][j] <= 100
    1 <= k <= 50

    Then u need to make a memoization using vector to have a better memory space
    Then that's the way to initialize a 3d vector:
    vector< vector< vector<int> > > memo(n + 1, vector<vector<int>> (m + 1, vector<int> (k, -1)));
 */

class Solution {
public:
    vector< vector< vector<int> > >  memo;
    int n, m, kk;
    int ans = 0;
    int MOD = 1e9 + 7;
    
    int solve(int x, int y, int sum, vector<vector<int>> &grid, vector<vector<vector<int>>> &memo) {
        if(x >= n or y >= m) return 0;
        
        sum += (grid[x][y])%kk;
        sum %= kk;
        
        if(memo[x][y][sum] != -1) return memo[x][y][sum];
        
        if(x == n - 1 && y == m - 1) {
            return (sum%kk == 0);
        }
        
        int a = solve(x + 1, y, sum, grid, memo);
        int b = solve(x, y + 1, sum, grid, memo);
        
        return memo[x][y][sum] = (a%MOD + b%MOD)%MOD;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        kk = k;
        vector< vector< vector<int> > > memo(n + 1, vector<vector<int>> (m + 1, vector<int> (k, -1)));
        
        return solve(0, 0, 0, grid, memo);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}