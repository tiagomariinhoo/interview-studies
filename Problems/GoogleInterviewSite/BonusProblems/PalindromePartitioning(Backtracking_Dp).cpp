#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/palindrome-partitioning/solution/
 * 
 * Backtracking Solution
 * 
 * To optimize, first is good store all range of idx such as
 * the substring are palindromes
 * 
 * After that, just do kinda knapsack backtracking to include
 * the current substring but taking care to pass the next position
 * that the next substring will starts
 * 
 * The solution runs in N * 2^N complexity time
 */ 

class Solution {
public:
    vector<vector<string> > ans;
    vector<pair<int, int> > palindromes;
    string globalString;
    
    string getStringFromRange(int i, int j) {
        string aux = globalString.substr(i, j - i + 1);
        return aux;
    }
    
    void solve(int pos, int posPalindromes, vector<string> aux) {
        if(pos == globalString.size() || posPalindromes == palindromes.size()) {
            ans.push_back(aux);
            return ;
        }
        
        for(int i = posPalindromes; i < palindromes.size(); i++) {
            if(palindromes[i].first == pos) {
                vector<string> aux2 = aux;
                aux2.push_back(getStringFromRange(palindromes[i].first, palindromes[i].second));
                solve(palindromes[i].second + 1, i + 1, aux2);
            }
        }
        
    }
        
    bool isPalindrome(int left, int right) {
        if(left == right) return true;
        int a = left, b = right;
        while(a < b) {
            if(globalString[a] != globalString[b]) return false;
            a++;
            b--;
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        globalString = s;
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(isPalindrome(i, j)) {
                    palindromes.push_back({i, j});
                }
            }
        }
        
        vector<string> aux;
        solve(0, 0, aux);
        
        return ans;
    }
};

/**
 * Using dynamic programming
 * 
 * Auxiliar Memory: N²
 * Solution Complexity Time: N * 2^N
 * 
 * Basically we can use the theory that:
 * if memo[i+1][j-1] is a palindrome and string[i] == string[j],
 * then the range [i...j] will also be a palindrome
 * 
 * Using it, I just need iterate through the string, checking
 * if there's a string[i] == string[currentPos] where 
 * memo[currentPos][i-1] is a palindrome, if it's true
 * I just need to continue the Dfs and my new currentPos will be
 * index i + 1
 * 
 * And is also important pass to the next step, the current vector<string> with all 
 * previous palindromes
 */

class Solution {
public:
    vector<vector<string> > ans;
    vector<pair<int, int> > palindromes;
    int memo[18][18];
    string globalString;
    
    void solve(int pos, vector<string> aux) {
        if(pos >= globalString.size()) {
            ans.push_back(aux);
            return ;
        }
        
        for(int i = pos; i < globalString.size(); i++) {
            if(globalString[i] == globalString[pos]) {
                if(i - pos <= 1 || memo[pos + 1][i - 1]) {
                    memo[pos][i] = 1;
                    vector<string> aux2 = aux;
                    aux2.push_back(globalString.substr(pos, i - pos + 1));
                    solve(i + 1, aux2);
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        globalString = s;
        
        vector<string> aux;
        solve(0, aux);
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}