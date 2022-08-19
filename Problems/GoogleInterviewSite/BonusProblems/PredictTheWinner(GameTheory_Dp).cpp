#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/predict-the-winner/submissions/
 * 
 * Classical game theory problem
 * 
 * Basically there are 2 players where they can take out one element from
 * the beginning or the end of the array. When they do that, will sum
 * in their answers
 * 
 * Just print if it's possible for player 1 win this game if both players are 
 * playing optimally
 * 
 * The problem can be solved recursively and let's imagine that the player one
 * is playing optimally and for each step, we want to get the maxScore for player 2
 * 
 * Always I'm getting vec[a] (player 1) - getMaxScore() (player 2)
 * 
 * The goal here is have at the end the total answer >= 0
 * Since
 * player1 - player2 >= 0
 * 
 * The problem can be solved in 2^n
 * But using dp we can optmize it
 */ 

class Solution {
public:
    
    vector<int> vec;
    long long int memo[21][21];
    
    int getMaxScore(int a, int b) {
        if(a == b) return vec[a];
        if(memo[a][b] != -1) return memo[a][b];
        
        int left = vec[a] - getMaxScore(a + 1, b);
        int right = vec[b] - getMaxScore(a, b - 1);
        
        return memo[a][b] = max(left, right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() == 1) return true;
        vec = nums;
        memset(memo, -1, sizeof memo);
        
        return getMaxScore(0, nums.size() - 1) >= 0;
    }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}