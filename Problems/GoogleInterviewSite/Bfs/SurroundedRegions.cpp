#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/surrounded-regions/submissions/
 * 
 * Problem also pretty easy
 * Just need to start from the borders, filling all islands with '.'
 * and after this, just change all remainder islands with X and put the '.' to 'O' again
 * 
 * Complexity is O(n*m) since u need to check all cells
 */ 

vector<vector<char>> vec;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

void dfs(int x, int y) {
  vec[x][y] = '.';
  for(int i=0;i<4;i++) {
    int xx = dx[i] + x;
    int yy = dy[i] + y;
    if(xx >= 0 && xx < vec.size() && yy >= 0 && yy < vec[xx].size()
    && vec[xx][yy] == 'O') {
      cout << xx << " - " << yy << endl;
      dfs(xx, yy);
    }
  }
}

void solve(vector<vector<char>>& board) {
  vec = board;

  int rowSize = vec.size();
  int colSize = vec[0].size();
  for(int i=0;i<rowSize;i++) {
    if(vec[i][0] == 'O') dfs(i, 0);
    if(vec[i][colSize - 1] == 'O') dfs(i, colSize - 1);
  }

  for(int i=0;i<colSize;i++) {
    if(vec[rowSize - 1][i] == 'O') dfs(rowSize - 1, i);
    if(vec[0][i] == 'O') dfs(0, i);
  }

  for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec[i].size();j++) {
      if(vec[i][j] == 'O') vec[i][j] = 'X';
    }
  }

  for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec[i].size();j++) {
      if(vec[i][j] == '.') vec[i][j] = 'O';
    }
  }

  for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec[i].size();j++) {
      board[i][j] = vec[i][j];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

// vector<vector<char>> input = {
//   {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}
// };
// vector<vector<char>> input = {
//   {'X','O','X'},{'X','O','X'},{'X','O','X'}
// };
vector<vector<char>> input = {
  {'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}
};
 solve(input);

  return 0;
}