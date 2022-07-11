#include <bits/stdc++.h>
using namespace std;

int rowSize, colSize;
int ans = -1;
string s;
string goal = "123450";
map<string, int> vis;

/**
 * U just need to try all possibilities using Bfs
 * 
 * The point for use Bfs here is that u can ensure the minimal numbers of steps
 * since u are trying all the adjacent cells first
 * 
 * The complexity time is O((m*n)!) but it's okay for this problem since u have
 * just 2 rows and 3 columns
 */ 

    // 1 2 3    0 1 2 3 4 5
    // 4 5 0 -> 1 2 3 4 5 0
    // -1 1 3 -> 0 pode 3 e 1, 2 pode 3 e -1, 3 pode 1 e 3


int getNewPosition(int pos, int i) {
    if(i == 0) {
        if(pos != 0 && pos != 3) return pos-1;
    } else if(i == 1) {
        return ((pos+3)%6);
    } else {
        if(pos != 2 && pos != 5) return pos+1;
    }

    return INT_MAX;
}

void solve(int pos, int it) {
    queue<pair<string, int> > q;
    q.push({s, 0});
    while(!q.empty()) {
        auto a = q.front();
        q.pop();

        string ss = a.first;
        int it = a.second;

        if(ss == goal) {
        if(ans == -1) ans = it;
        else ans = min(ans, it);
        return ;
    }
        
        vis[ss] = 1;
        int pos = 0;
        for(int i=0;i<ss.size();i++) if(ss[i] == '0') pos = i;

        for(int i=0;i<3;i++) {
            int newPos = getNewPosition(pos, i);
            if(newPos == INT_MAX) continue;

            swap(ss[newPos], ss[pos]);
            if(!vis[ss]) {
                q.push({ss, it + 1});
            }
            swap(ss[newPos], ss[pos]);
        }
    }
    
}

int slidingPuzzle(vector<vector<int>>& board) {
    rowSize = board.size();
    colSize = board[0].size();

    for(int i=0;i<rowSize;i++) {
        for(int j=0;j<colSize;j++) {
            s += board[i][j] + '0';
        }
    }

    int pos = 0;
    for(int i=0;i<s.size();i++) if(s[i] == '0') pos = i;
    cout << pos << endl;
    solve(pos, 0);

    return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

//   vector<vector<int>> vec = {{1,2,3},{4,0,5}};
  vector<vector<int>> vec = {{4,1,2},{5,0,3}};

  slidingPuzzle(vec);

  return 0;
}