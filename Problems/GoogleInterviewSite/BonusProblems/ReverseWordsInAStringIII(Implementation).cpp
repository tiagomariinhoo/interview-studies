#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/
 * 
 * Just separate words and inverse each one of them
 * Linear time
 */ 

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> words;
        
        string aux = "";
        for(auto i : s) {
            if(i == ' ') {
                words.push_back(aux);
                aux = "";
            } else {
                aux += i;
            }
        }
        
        if(aux != "") words.push_back(aux);
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = words[i].size() - 1; j >= 0; j--) {
                ans += words[i][j];
            }
            if(i < words.size() - 1) ans += " ";
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}