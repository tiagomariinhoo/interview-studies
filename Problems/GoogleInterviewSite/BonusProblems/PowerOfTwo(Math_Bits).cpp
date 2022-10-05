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
 * https://leetcode.com/problems/power-of-two/submissions/
 * 
 * Easy problem and can be solved in O(32 bits)
 * 
 * U just need to check bit by bit if (1 << i) == n
 * but there's a corner case about numbers <= 0
 * 
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        for(int i = 0; i < 32; i++) {
            if(n == (1 << i)) return true;
        }
        
        return false;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}