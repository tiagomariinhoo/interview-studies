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
 * https://leetcode.com/submissions/detail/793242438/
 * 
 * Similar to knap dp, just try to do all steps. The corner
 * case here is that u can go to a negative point, to treat this
 * u can start the position + 2000 and make the negative point < 2000
 * 
 * Solution runs in n * steps complexity time
 * with the same memory space aux
 */

class Solution {
public:
    int start, end;
    int memo[5002][1002];
    int MOD = 1e9 + 7;
    
    int solve(int current, int steps) {
        if(current < 0 or steps < 0) return 0;
        
        if(steps == 0) {
            if(current == end) return 1;
            return 0;
        }
        
        if(memo[current][steps] != -1) return memo[current][steps];
        
        int a = solve(current - 1, steps - 1)%MOD;
        int b = solve(current + 1, steps - 1)%MOD;
        
        return memo[current][steps] = (a+b)%MOD;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        start = startPos + 2000;
        end = endPos + 2000;
        
        memset(memo, -1, sizeof memo);
        
        return solve(startPos + 2000, k);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}