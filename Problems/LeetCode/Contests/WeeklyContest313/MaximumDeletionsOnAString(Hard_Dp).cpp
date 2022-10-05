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
 * https://leetcode.com/problems/maximum-deletions-on-a-string/
 * 
 * Can be solved in ~n2 using dp
 * 
 * One interesting thing here is that use string.compare is better
 * than use string.substr and compare.
 * Interesting and hard problem
 * 
 */

class Solution {
public:
    
    int memo[4101];
    string globalString;
    
    int solve(int pos) {
        if(memo[pos] != -1) return memo[pos];
        int a = 1;
        
        for(int i = pos + 1; i < globalString.size(); i++) {
            // string sub = globalString.substr(pos, (i - pos));
            // string sub2 = globalString.substr(i, (i - pos)); TLE using this
            if(globalString.compare(i, i - pos, globalString, pos, i - pos) == 0) {
                a = max(a, solve(i) + 1);
            }
        }
        
        return memo[pos] = a;
    }
    
    int deleteString(string s) {
        memset(memo, -1, sizeof memo);
        globalString = s;
      
        return solve(0);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}