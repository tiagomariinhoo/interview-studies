#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/license-key-formatting/submissions/
 */ 

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string answer = "";
        
        for(auto &i : s) {
            i = toupper(i);
        }
        
        bool at = false;
        string aux = "";
        
        for(auto i : s) {
            if(i != '-')
            aux += i;
        }
        
        string group = "";
        
        for(int i = aux.size() - 1; i >= 0; i--) {
            group += aux[i];
            if(group.size() == k) {
                if(answer != "") {
                    answer += "-";
                }
                answer += group;
                group = "";
            }
        }
        
        if(group != "") {
            if(answer != "") {
                answer += "-";
            }
            answer += group;
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};

int main() {


  return 0;
}