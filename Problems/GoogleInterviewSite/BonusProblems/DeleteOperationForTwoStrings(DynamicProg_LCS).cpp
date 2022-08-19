#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/delete-operation-for-two-strings/submissions/
 * 
 * For this problem u just need to make two strings equal after
 * delete characters
 * 
 * My approach was using Longest Common Subsequence (LCS), I can
 * use it to get the longest subsequence in word1, from word2
 * Basically if I have:
 * word1 - ABCFEG
 * word2 - BCET
 * 
 * The longest common subsequence is: BCE
 * 
 * Then using LCS I can get it in quadratic time
 * 
 * Just comparing char by char,
 * if word[i] == word[j] my answer can be:
 * memo[i-1][j-1] + 1 (that should be the best answer until the last char but adding one)
 * memo[i-1][j], memo[i][j-1] (that should be the current best answer)
 * 
 * Complexity time: O (word1.size * word2.size)
 */ 

class Solution {
public:
    int memo[501][501];
    
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size()) swap(word1, word2);
        map<int, int> qt, qt2;
        
        int a = 0;
        
        int ans = INT_MAX;
        
        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    memo[i][j] = max({
                        memo[i - 1][j],
                        memo[i][j - 1],
                        memo[i - 1][j - 1] + 1
                    });
                } else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j - 1]);
                }
            }
        }
        
        int lcs = memo[word1.size()][word2.size()];
        ans = ((word1.size() - lcs) + (word2.size() - lcs));
        
        // cout << "Lcs: " << lcs << endl;
        
        return ans;
    }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}