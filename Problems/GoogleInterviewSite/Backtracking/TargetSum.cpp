#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/target-sum/submissions/
 * 
 * Initially would be a backtracking problem but
 * I only solved using dynamic programming.
 * 
 * Basically you can use the constraints and besides that, 
 * you can use 1 dp to store the negative sums
 * and 1 dp to store positive sums
 * 
 * Nice problem
 */

class Solution {
public:
    
    int globalTarget;
    vector<int> globalNums;
    int dp[1001][22];
    int dp2[1001][22];
    
    int solve(int idx, int sum) {
        if(idx == globalNums.size()) {
            if(sum == globalTarget) return 1;
            return 0;
        }
        
        if(sum < 0) {
            if(dp[abs(sum)][idx] != -1) return dp[abs(sum)][idx];
        } else {
            if(dp2[abs(sum)][idx] != -1) return dp2[abs(sum)][idx];
        }
        
        int a = solve(idx + 1, sum + globalNums[idx]);
        int b = solve(idx + 1, sum - globalNums[idx]);
        
        if(sum < 0) {
            return dp[abs(sum)][idx] = (a + b);
        } else {
            return dp2[abs(sum)][idx] = (a + b);
        }
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        globalTarget = target;    
        globalNums = nums;
        
        for(int i=0;i<=1000;i++) {
            for(int j=0;j<=20;j++) {
                dp[i][j] = -1;
                dp2[i][j] = -1;
            }
        }
        
        return solve(0, 0);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}