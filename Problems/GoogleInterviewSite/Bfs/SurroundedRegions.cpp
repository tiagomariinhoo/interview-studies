#include <bits/stdc++.h>
using namespace std;

int count = 0;
vector<vector<int> > vec;

int solve(int x, int y) {
  count++;
  if(count == 1e5) return INT_MAX;

} 

int slidingPuzzle(vector<vector<int>>& board) {
  vec = board;
  for(int i=0;i<board.size();i++) {
    for(int j=0;j<board[i].size();j++) {
      if(board[i][j] == 0) {
        for(int k=0;k<4;k++) {

        }
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> input = {{4, 1, 2}, {5, 0, 3}};
  slidingPuzzle(input);

  return 0;
}