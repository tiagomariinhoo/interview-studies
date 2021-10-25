#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/palindrome-partitioning/submissions/
 * 
 * The solution for this problem is just try to generate all the substrings/subsets
 * And test each one of them. I just need to push into my list if the string is a palindrome
 * Since they are a palindrome, when my current String is empty, I just need to push my current list
 * on my answer.
 * 
 * I think the complexity time is:
 * n * (2ˆn), where N is the size of the string
 * 
 * Cause when Im checking if my current substring is a palindrome
 * This takes linear time, and I have the option to either put my substring on my
 * list or not.
 */

class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(int l, int r, string globalString) {
        int a = l, b = r;
        while(a < b) {
            if(globalString[a] != globalString[b]) return false;
            a++, b--;
        }
        
        return true;
    }
    
    void solve(vector<string> currentList, string currentString) {
        
        if(currentString == "") {
            ans.push_back(currentList);
            return ;
        }
        
        for(int i=0;i<currentString.size();i++) {
            if(isPalindrome(0, i, currentString)) {
                vector<string> aux = currentList;
                aux.push_back(currentString.substr(0, i+1));
                string aux2 = currentString.substr(i+1, currentString.size());
                
                solve(aux, aux2);
            }
        }
    }    

    vector<vector<string>> partition(string s) {
        vector<string> cur;
        solve(cur, s);
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}