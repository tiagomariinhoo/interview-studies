#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/repeated-substring-pattern/
 * 
 * Pretty easy problem, just try to build a new string with the current
 * pattern if and only if the current size pattern is a divider
 * 
 * Solution runs in n * sqrt(n)
 */ 

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string ans = "";
        
        for(int i = 0; i < s.size()/2; i++) {
            ans += s[i];
            if(s.size()%ans.size() == 0) {
                int qt = (s.size() / ans.size());
                string aux = "";
                for(int j = 0; j < qt; j++) {
                    aux += ans;
                }
                if(aux == s) return true;
            }
        }
        
        return false;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}