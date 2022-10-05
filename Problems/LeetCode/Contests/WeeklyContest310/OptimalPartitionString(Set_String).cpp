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
 * https://leetcode.com/contest/weekly-contest-310/problems/optimal-partition-of-string/
 * 
 * Just use a set to store the current chars and 
 * if already exist in the set, this means that is a new
 * partition
 * 
 * n log n
 */

class Solution {
public:
    int partitionString(string s) {
        set<int> aux;
        int ans = 0;
        
        int qt = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(aux.find(s[i] - '0') != aux.end()) {
                ans++;
                aux.clear();
                aux.insert(s[i] - '0');
            } else {
                aux.insert(s[i] - '0');
            }
        }
        
        if(aux.size() > 0) ans++;
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}