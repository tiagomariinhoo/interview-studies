#include <bits/stdc++.h>

using namespace std;

/**
 * Solution using Edit Distance DP, an extension from LCS
 * https://youtu.be/XYi2-LPrwm4 -- NeetCode Explanation
 * 
 * Basically u need to see that initially, there are 2 possibilities:
 * (assuming that u want to transform string1 into string2)
 * 
 * 1 - When string1[i] == string2[j]
 * 2 - When string1[i] != string2[j]
 * 
 * In the first case, u can notice that u just need to move the both pointers
 * since you don't want to spend a movement.
 * 
 * In the second case, there are three possibilities:
 * 1 - Add a character
 * 2 - Delete a character 
 * 3 - Replace a character
 * 
 * For the first case, the case where u add a character into the string1
 * this means that u just need to move the pointer j, since u theoretically
 * added a character and now u need to compare the same previous character.
 * 
 * For the second case, you just move the pointer i, since u deleted the curernt
 * character
 * 
 * For the third case, u need to move the both points, since u make them equal
 * 
 * The point for this dynamic programming is the tabulation, you need to 
 * take care about the base case. 
 * 
 * You can see in the video that the base case for each one of the strings
 * are:
 * 
 *  a b c
 * a      4
 * d      3 
 * f      2 
 * g      1 
 *  3 2 1 0 
 * 
 * Since u need to suppose that in [0][word1.size()] = word2.size()
 * is the case that if u don't have any character in word1, 
 * u will spend 4 movements to to make it
 * 
 * The case where u get (i + 1, j + 1) is the case that word1[i] == word2[j]
 * and the case where (i + 1, j), is when u're deleting a character from word1
 * and (i, j + 1), is the case where u add a character from word1
*/             

class Solution {
public:
    int minDistance(string word1, string word2) {
        int memo[word1.size() + 5][word2.size() + 5];
        memset(memo, 0, sizeof memo);

        for(int i = 0; i < word2.size(); i++) {
            memo[word1.size()][i] = word2.size() - i;
        }

        for(int i = 0; i < word1.size(); i++) {
            memo[i][word2.size()] = word1.size() - i;
        }

        memo[word1.size()][word2.size()] = 0;

        for(int i = word1.size() - 1; i >= 0; i--) {
            for(int j = word2.size() - 1; j >= 0; j--) {
                if(word1[i] == word2[j]) {
                    memo[i][j] = memo[i + 1][j + 1];
                } else {
                    memo[i][j] = min({
                        memo[i + 1][j + 1] + 1,
                        memo[i + 1][j] + 1,
                        memo[i][j + 1] + 1
                    });
                }
            }
        }

        for(int i = 0 ; i <= word1.size(); i++) {
            for(int j = 0; j <= word2.size(); j++) {
                cout << memo[i][j] << " ";
            } cout << endl;
        }

        return memo[0][0];   
    }
};

int main () {

  return 0;
}