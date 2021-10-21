#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/word-search/submissions/
 * 
 * This problem was one of the most interesting problems that I did.
 * Basically you have a grid that containing chars and u need find
 * a word inside the grid. Its a backtracking problem.
 * 
 * The most important point is:
 * When u pass the board by parameter, u need to pass the references
 * Its a important point to get Accepted cause when u dont pass the references
 * the Cpp pass a copy under the table and this is really heavy for the
 * complexity time.
 * 
 * The solution runs in n * m * 4 ^ sizeOfString
 * 
 */ 

class Solution {
public:
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    string globalWord;
    bool answer;
    
    void solve(int x, int y, string s, vector<vector<char>> &board) {
        if(answer) return ;
        if(board[x][y] != globalWord[s.size()]) return ;
        
        s += board[x][y];
        char current = board[x][y];
        board[x][y] = '*';
        
        if(s.size() == globalWord.size()) {
            if(s == globalWord) {
                answer = true;
            }
            
            return ;
        }

        for(int i=0;i<4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx >= 0 and xx < board.size() and yy >= 0 and yy < board[x].size() && board[xx][yy] != '*') {
                solve(xx, yy, s, board);
            }
        }
        board[x][y] = current;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        globalWord = word;
        
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                solve(i, j, "", board);
            }
        }
        
        return answer;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}