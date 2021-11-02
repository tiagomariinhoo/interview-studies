#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/unique-paths/
 * 
 * Solution runs in O (m * n)
 */

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int memo[101][101];
    int globalM, globalN;
    
    int solve(int x, int y) {
        if(x == globalM and y == globalN) {
            return 1;
        } else if(x > globalM or y > globalN) return 0;
        
        if(memo[x][y] != -1) return memo[x][y];
        
        
        int a = solve(x + 1, y);
        int b = solve(x, y + 1);
        
        return memo[x][y] = a + b;
    }
    
    int uniquePaths(int m, int n) {
        globalM = m;
        globalN = n;
        
        memset(memo, -1, sizeof memo);
        return solve(1, 1);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}