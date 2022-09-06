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
 * https://leetcode.com/submissions/detail/793229915/
 * 
 * Just check the distance between the letters storing if is the first
 * time that u're passing through the letter. Checking if the distance
 * match with the distance array
 */

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<int, int> vis;
        for(int i = 0; i < s.size() - 1; i++) {
            int cur = s[i] - 'a';
            if(vis[cur]) continue;
            vis[cur] = 1;
            for(int j = i + 1; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    if(j - i - 1 != distance[cur]) return false;
                }
            }
        }
        
        return true;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}