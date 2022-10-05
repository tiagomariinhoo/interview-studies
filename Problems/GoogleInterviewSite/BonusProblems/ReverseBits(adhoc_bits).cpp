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
 * https://leetcode.com/problems/reverse-bits/
 * 
 * Just adhoc and easy problem, can be solved
 * in linear time where N is 32 bits
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t aux = 0;
        vector<int> bits;
        for(int i = 0; i < 32; i++) {
            if(n & (1 << i)) bits.push_back(1);
            else bits.push_back(0);
        }
        reverse(bits.begin(), bits.end());
        for(int i = 0; i < 32; i++) {
            if(bits[i] == 1) aux += pow(2, i);
        }
        
        return aux;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}