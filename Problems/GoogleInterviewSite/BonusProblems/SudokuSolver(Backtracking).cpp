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
 * https://leetcode.com/problems/sudoku-solver/
 * 
 */


class Solution {
public:
    
    bool at = false;
    
    bool isValid(vector<vector<char>>& board,int row,int col,char ch)
    {
        for (int i=0;i<9;i++)
        {
            if (board[row][i] == ch)
            {
                return false;
            }
            if (board[i][col] == ch)
            {
                return false;
            }
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == ch)
            {
                return false;
            }
        }
        return true;
    }
    
     bool solve(vector<vector<char>>& board)
    {
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {                
                if (board[i][j] == '.')
                {
                    for( char c='1';c<='9';c++)
                    {
                        if (isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                            if (solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}