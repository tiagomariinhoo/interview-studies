#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/number-of-islands/
 * 
 * Just a normal bfs in matrix, taking care of 
 * change the island cell for . to mark as visited
 * 
 * Complexity time: N²
 */ 

class Solution {
public:
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void dfs(int x, int y, vector<vector<char>> &grid) {
        grid[x][y] = '.';
        
        for(int i=0;i<4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx >= 0 and xx < grid.size() and yy >= 0 and yy < grid[xx].size()) {
                if(grid[xx][yy] == '1') {
                    dfs(xx, yy, grid);
                }
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
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