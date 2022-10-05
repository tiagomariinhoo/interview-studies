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
 * https://leetcode.com/problems/island-perimeter/submissions/
 * 
 * Just find island cells and check if there are adjacent cells
 * to remove one from perimeter
 * 
 * Solution in n * m
 */

class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    
    int solve(int x, int y, vector< vector<int> > &grid) {
        int sum = 4;
        grid[x][y] = -1;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[xx].size()) {
                if(grid[xx][yy] == 1) {
                    sum--;
                    sum += solve(xx, yy, grid);
                } else if(grid[xx][yy] == -1) {
                    sum--;
                }
            }
        }
        
        return sum;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0 ; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    ans += solve(i, j, grid);
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    for(int k=0;k<4;k++) {
                        int xx = i + dx[k];
                        int yy = j + dy[k];

                        if(xx >= 0 and xx < grid.size() and yy >= 0 and yy < grid[i].size()) {
                            if(grid[xx][yy] == 0) {
                                ans++;
                            }
                        } else ans++;
                    }   
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