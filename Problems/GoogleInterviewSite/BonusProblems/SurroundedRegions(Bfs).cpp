#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/surrounded-regions/
 * 
 * Complexity: O(N*M)
 * 
 * For each cell that I found with an 'O', I need to try
 * to hide all the other adjacent cells with 'O' since that
 * it's not a border
 * 
 * Basically I started from the borders looking for cells
 * 'O' and start a dfs to change all cells to '.'
 * 
 * After that, all remaining cells, will be 'X' or 'O'
 * 
 * I can change all 'O' cells to 'X' because this means that
 * are surrounded regions
 * 
 * After that, I just put the cells '.' back to 'O' cause
 * those cells are cells linked to the borders
 * 
 */ 

class Solution {
public:
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

  for(auto i : vec) {
    for(auto j : i) {
      cout << j << " " ;
    } cout << endl;
  }
  cout << endl;

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

  for(auto i : vec) {
    for(auto j : i) {
      cout << j << " " ;
    } cout << endl;
  }
  cout << endl;

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

  for(auto i : vec) {
    for(auto j : i) {
      cout << j << " " ;
    } cout << endl;
  }

  for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec[i].size();j++) {
      board[i][j] = vec[i][j];
    }
  }
}

};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}