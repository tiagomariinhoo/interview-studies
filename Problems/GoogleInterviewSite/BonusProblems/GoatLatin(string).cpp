#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/goat-latin/submissions/
 * 
 * Just an implementation problem
 * and just be careful with the lowercase and uppercase
 * letters
 */ 

class Solution {
public:
    
    vector<string> getWords(string sentence) {
        string aux = "";
        vector<string> words;
        
        for(auto i : sentence) {
            if(i == ' ') {
                words.push_back(aux);
                aux = "";
            } else {
                aux += i;
            }
        }
        
        if(aux.size() > 0) {
            words.push_back(aux);
        }
        
        return words;
    }
    
    bool startWithVowel(string s) {
        if(s[0] == 'a' ||
          s[0] == 'e' || 
          s[0] == 'i' ||
          s[0] == 'o' ||
          s[0] == 'u' ||
          s[0] == 'A' ||
          s[0] == 'E' || 
          s[0] == 'I' ||
          s[0] == 'O' ||
          s[0] == 'U') {
            return true;
        }
        
        return false;
    }
    
    string changeConsonantWord(string s) {
        char begin = s[0];
        
        for(int i = 0; i < s.size() - 1; i++) {
            s[i] = s[i + 1];
        }
        
        s[s.size() - 1] = begin;
        
        return s;
    }
    
    string toGoatLatin(string sentence) {
        vector<string> words = getWords(sentence); 
        string ans = "";
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            
            if(startWithVowel(word)) {
                ans += word;
            } else {
                ans += changeConsonantWord(word);
            }
            
            ans += "ma";
            for(int j = 1; j <= (i+1); j++) {
                ans += "a";
            }
            
            if(i < words.size() - 1) {
                ans += " ";
            }
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}