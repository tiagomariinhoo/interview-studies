#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/reverse-words-in-a-string/submissions/
 */

class Solution {
public:
    string reverseWords(string s) {
        vector<string> aux;
        string aux2 = "";
        
        for(auto i : s) {
            if(i != ' '){
                aux2 += i;
            } else {
                if(aux2 != "") aux.push_back(aux2), aux2 = "";
            }
        }
        
        if(aux2 != "") aux.push_back(aux2);
        
        reverse(aux.begin(), aux.end());
        string answer = "";
        
        for(int i = 0; i < aux.size(); i++) {
            if(aux[i] == "") continue;
            
            if(i) answer += " ";
            answer += aux[i];
        }
        
        return answer;
    }
};

int main() {

  return 0;
}