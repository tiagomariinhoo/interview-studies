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
 * https://leetcode.com/problems/valid-perfect-square/
 * 
 * Using the binary search lower bound to check the solution
 * 
 * log (2^32 / 2)
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l = 1, r = num/2;
        while(l < r) {
            long long int mid = l + (r - l) / 2; // avoid l = mid
            
            if(mid * mid < num) l = mid + 1;
            else r = mid;
        }
        
        return (l * l == num);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}