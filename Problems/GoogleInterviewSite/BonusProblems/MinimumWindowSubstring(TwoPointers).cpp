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
 * https://leetcode.com/problems/minimum-window-substring/submissions/
 * 
 * Using two pointers, it's possible to solve it in 52 * (n + m)
 * 
 * Where u just need to keep looping through the string always
 * updating the qt for each letter. If u find a situation that
 * there's a current letter missing, the u need to update the
 * right pointer, if u have a situation that there's no letter
 * missing, u can move the left pointer and try to find another
 * substring
 */

class Solution {
public:
    int qtAux[150];
    int qt[150];
    int l = -1, r = -1;
    string globalString;
    
    
    string minWindow(string s, string t) {
        
        int a = 0, b = 0;
        
        for(auto i : t) qtAux[i - 'A']++;
        
        while(a < s.size()) {
            while(b < s.size()) {
                qt[s[b] - 'A']++;
                bool at = false;
                
                for(int i = 0; i < 150; i++) {
                    if(qt[i] < qtAux[i]) {
                        // char current = i + 'A';
                        // cout << current << endl;
                        at = true;
                        break;
                    }
                }
                
                if(!at) {
                    if((l == -1) || (l != -1 && (b - a < r - l))) {
                        l = a;
                        r = b;
                    } 
                    qt[s[b] - 'A']--;
                    break;
                }
                b++;
            }
            
            qt[s[a] - 'A']--;
            a++;
        }
        
        if(l != -1) {
            return s.substr(l, r - l + 1);
        }
        
        return "";
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}