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
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * 
 * Just try all combinations using a recursion like a knap
 * 
 * Complexity time n * 4^n
 */

class Solution {
public:
    
    map<char, string> mp;
    string globalDigits;
    vector<string> ans;
    
    void solve(int idx, string current) {
        if(idx == globalDigits.size()) {
            if(current != "") {
                ans.push_back(current);    
            }
        }
        
        for(auto i : mp[globalDigits[idx]]) {
            solve(idx + 1, current + i);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        globalDigits = digits;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        solve(0, "");
        
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}