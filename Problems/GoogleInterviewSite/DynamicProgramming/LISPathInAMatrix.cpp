#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/
 * 
 * It's a pretty good problem, you just need to find the LIS in a matrix.
 * 
 * Basically just make a normal Bfs in a matrix and store the LIS from there.
 * Classical dp problem in matrix, the solution runs in N*M
 * 
 */ 

class Solution {
public:
    vector<vector<int> > vec;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int n, m;
    int ans = 1;
    int memo[201][201];
    
    int solve(int x, int y) {
        if(memo[x][y] != -1) return memo[x][y];
        
        int aux = 0;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx >= 0 && xx < n && yy >= 0 && yy < m) {
                if(vec[xx][yy] > vec[x][y]) {
                    int auxx = vec[x][y];
                    vec[x][y] = -1;
                    aux = max(aux, solve(xx, yy) + 1);
                    vec[x][y] = auxx;
                }
            }
        }
        
        return memo[x][y] = aux;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vec = matrix;
        n = vec.size();
        m = vec[0].size();
        memset(memo, -1, sizeof memo);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(memo[i][j] == -1) {
                    solve(i, j);
                    ans = max(ans, memo[i][j] + 1);
                }
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