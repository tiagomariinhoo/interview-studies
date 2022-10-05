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
 * https://leetcode.com/problems/rotting-oranges/
 * (n*m)², since n * m <= 100, for each it
 * just keep expanding the rotting oranges storing the
 * smallest time
 */ 

class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    vector<vector<int> > vec;
    
    bool at = true;
    
    /*
    Since n * m <= 100
    Then we just need to keep expanding one by one but always storing the smallest answer
    */
    
    int orangesRotting(vector<vector<int>>& grid) {
        for(int k = 0; k < 100; k++) {
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    if(grid[i][j] >= 2) {
                        int current = grid[i][j];
                        for(int kk = 0; kk < 4; kk++) {
                            int xx = i + dx[kk];
                            int yy = j + dy[kk];
                            if(xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[i].size()) {
                                if(grid[xx][yy] == 1) {
                                    grid[xx][yy] = current + 1;
                                } else if(grid[xx][yy] >= 2) {
                                    grid[xx][yy] = min(grid[xx][yy], current + 1);
                                }
                            }
                        }
                    }
                }
            }   
        }
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) return -1;
                else if(grid[i][j] >= 2) {
                    ans = max(ans, grid[i][j] - 2);
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