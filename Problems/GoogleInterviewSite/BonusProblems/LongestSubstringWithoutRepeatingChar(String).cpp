#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 * Can be solved in linear time or n log n
 * Just keep using two pointers to add chars
 */ 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> aux;
        int ans = 0;
        
        /*
        abcabcbb
        
        a = 0, b = 0;
        a = 0, b = 2
        a b c
        a = 0, b = 3
        a b c a
        a = 1, b = 3
        b c a
        */
        int a = 0, b = 0;
        // Can be done in linear time using unordered_map/array too
        while(a < s.size()) {
            while(b < s.size()) {
                if(aux.find(s[b]) != aux.end()) {
                    break;
                }
                aux.insert(s[b]);
                if(aux.size() > ans) ans = aux.size();
                b++;
            }
            
            aux.erase(s[a]);
            a++;
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}