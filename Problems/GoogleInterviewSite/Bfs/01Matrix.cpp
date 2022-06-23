#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/01-matrix/submissions/
 * 
 * This problem is pretty easy, you just need to realize that
 * you can put all cells with 0's in a queue to run bfs.
 * 
 * Using it, you can go into all adjacents cells and keep filling up everyone.
 * The complexity for this problem is just a bfs, running in O (N*M)
 */ 

int INTT_MAX = 101010;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  vector<vector<int>>ans (mat.size(), vector<int>(mat[0].size(), INTT_MAX));
  queue<pair<int, int> > q;

  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};

  for(int i=0;i<mat.size();i++) {
    for(int j=0;j<mat[i].size();j++) {
      if(mat[i][j] == 0) {
        ans[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  while(!q.empty()) {
    auto element = q.front();
    q.pop();

    int x = element.first;
    int y = element.second;

    for(int i=0;i<4;i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if(xx >= 0 && xx < mat.size() && yy >= 0 && yy < mat[xx].size()) {
        if(ans[xx][yy] == INTT_MAX) {
          ans[xx][yy] = ans[x][y] + 1;
          q.push({xx, yy});
        } else {
          ans[xx][yy] = min(ans[xx][yy], ans[x][y] + 1);
        }
      }
    }
  }

  for(auto i : ans) {
    for(auto j : i) {
      cout << j << " ";
    } cout << endl;
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // vector<vector<int>> in = {{0,0,0},{0,1,0},{0,0,0}};

  vector<vector<int>> in = {{0,0,0},{0,1,0},{1,1,1}};

  updateMatrix(in);

  return 0;
}