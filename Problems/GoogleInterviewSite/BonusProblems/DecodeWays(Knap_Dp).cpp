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
 * https://leetcode.com/problems/decode-ways/submissions/
 * 
 * Just do a normal knapsack with dynamic programming
 * 
 * The solution runs in lineart time, basically,
 * but u just need to becareful about the lead zeroes
 * and the number always in range 1 ... 26
 * 
 * Linear auxiliary space too
 */

class Solution {
public:
    int memo[101];
    string globalString;
    
    int solve(int pos) {
        if(pos >= globalString.size()) return 1;
        if(globalString[pos] == '0') return 0;
        
        if(memo[pos] != -1) return memo[pos];
        
        int a = 0;
        a += solve(pos + 1);
        if(pos < globalString.size() - 1 && 
           ((globalString[pos] == '1' && globalString[pos + 1] <= '9') || 
          (globalString[pos] == '2' && globalString[pos + 1] <= '6'))) {
            a += solve(pos + 2);
        }
        
        return memo[pos] = a;
    }
    
    int numDecodings(string s) {
        globalString = s;
        
        memset(memo, -1, sizeof memo);
        
        return solve(0);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}