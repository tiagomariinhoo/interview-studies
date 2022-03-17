#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(3*1e5 + 5)
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
 * https://leetcode.com/problems/counting-bits/
 * 
 * There are two ways to solve this problem.
 * 
 * The first one is using a simple implementation where
 * I can count the bits just shifting 1 bit. Then for each number
 * I just need to compare the bit 1 in each position and check
 * if it's true. The complexity is N * (32) cause the wrost case
 * I need check 32 bits.
 * 
 * The second one is just using builtin_popcount from C++
 * That will returns the number of checked bits in the number.
 */

// vector<int> countBits(int n) {
//   vector<int> ans;

//   for(int i = 0; i <= n; i++) {
//     int j = 0;
//     int aux = 0;
//     while((1 << j) <= i) {
//       if((1 << j) & i) aux++;
//       j++;
//     }
//     ans.push_back(aux);
//   }

//   return ans;
// }

vector<int> countBits(int n) {
  vector<int> ans;

  for(int i = 0; i <= n; i++) {
    ans.push_back(__builtin_popcount(i));
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> ans = countBits(3);

  for(auto i : ans) cout << i << endl;

  return 0;
}