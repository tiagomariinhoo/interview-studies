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
 * https://leetcode.com/contest/weekly-contest-313/problems/minimize-xor/
 * 
 * Just count the bits, giving preference for the leftmost bits
 * 
 * O(32)
 * 
 */
class Solution {
public:
    map<int, int> vis;
    
    int minimizeXor(int num1, int num2) {
        int dif = __builtin_popcount(num2);
        int bits = __builtin_popcount(num1);
        
        int ans = 0;
        
        for(int i = 31; i >= 0; i--) {
            if((num1 & (1 << i)) && dif) {
                vis[i] = 1;
                ans |= (1 << i);
                dif--;
            }
        }
        
            for(int i = 0; i < 32; i++) {
                if(!vis[i] && dif) {
                    ans |= (1 << i);
                    dif--;
                    vis[i] = 1;
                }
            }
        
        return ans;
    }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}