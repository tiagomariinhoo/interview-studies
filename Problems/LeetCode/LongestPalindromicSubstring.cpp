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
 * https://leetcode.com/problems/longest-palindromic-substring/
 * Dynamic Programming
 * 
 * The naive solution for this problem is just solve in cubic time, testing all substrings
 * but this can take O(n³)
 * 
 * The better approach is using Dynamic Programming. Basically u just need to
 * store in a table for each substring (i, j) if the substring is a palindrome.
 * If u keep expanding from the center, u can see that if (i, j) is a palindrome
 * then (i-1, j+1) is also a palindrome if and only if s[i-1] == s[j+1].
 * Then u just need to fill the table using the substrings if len 1 and 2 and
 * keep expanding recursively.
 * 
 * This can take Quadratic time O(n²)
 * And time space O(n²) as well
 */

string ss;
int memo[1001][1001];
string ans;

void solve(int i, int j) {
  if(i == (j - 1)) return;
  if(memo[i][j] != -1) return;

  solve(i+1, j);
  solve(i, j-1);
  
  if(memo[i+1][j-1] == 1 && ss[i] == ss[j]) {
    memo[i][j] = 1;
  } else memo[i][j] = 0;
}

string longestPalindrome(string s) {
  ss = s;
  memset(memo, -1, sizeof memo);
    for(int i=0;i<s.size();i++) {
      memo[i][i] = 1;
      if(i < s.size() - 1) {
        if(s[i] == s[i+1]) memo[i][i + 1] = 1;
      }
    }
  
  solve(0, s.size() - 1);

  pair<int, int> anss;
  for(int i=0;i<s.size();i++) {
    for(int j=i;j<s.size();j++) {
      if(memo[i][j] == 1 && (j - i) > anss.second - anss.first) {
        anss.first = i;
        anss.second = j;
      }
    }
  }

  string aa = s.substr(anss.first, anss.second - anss.first + 1);
  cout << aa << endl;
  return aa;
}

/**
 * Solution in square time
 * Just using the normal idea of using a memoization to check
 * if the s[i+1][j-1] is also a palindrome
 */ 

class Solution {
public:
    int memo[1010][1010];
    string globalString;
    int l = 0, r = 0;
    
    int solve(int i, int j) {
        if(i < 0 or j >= globalString.size() || i > j) return 0;
        if(i == j) return memo[i][j] = 1;
        if(memo[i][j] != -1) return memo[i][j];
        
        
        int c = solve(i + 1, j);
        int b = solve(i, j - 1);
        int a = solve(i + 1, j - 1);
        
        if(globalString[i] == globalString[j] && a || globalString[i] == globalString[j] && j - i <= 1) {
            if((j - i) > (r - l)) l = i, r = j;
            return memo[i][j] = 1;
        }
        
        return memo[i][j] = 0;
    }
    
    string longestPalindrome(string s) {
        globalString = s;
        memset(memo, -1, sizeof memo);
    
        solve(0, s.size() - 1);
        
        return s.substr(l, (r - l) + 1);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  longestPalindrome("aacabdkacaa");

  return 0;
}