#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/target-sum/submissions/
 * 
 * Interesting Dp problem, u receive an array that u need
 * to sum or subtract each element to have the target number
 * 
 * U just need to try sum or subtrack each number but there is a corner case
 * it's important always deal with the sum + 20000, since the biggest sum is 20000
 * then the current sum will be always >= 0, if the sum is < 0, might have an exec error
 * for the index in dp
 * 
 * The complexity time is n * sum
 * 
 * Space : n * sum
 */ 

class Solution {
public:
    vector<int> vec;
    int globalTarget;
    int ans = 0;
    
    int dp[21][40001];
    
    int solve(int pos, int target) {
        if(target == globalTarget && pos == vec.size()) {
            return dp[pos][target + 20000] = 1;
        } 
        
        if(pos == vec.size()) {
            return dp[pos][target + 20000] = 0;
        }
        if(dp[pos][target + 20000] != -1) {
            return dp[pos][target + 20000];
        }
        
        int a = solve(pos + 1, target + vec[pos]);
        int b = solve(pos + 1, target - vec[pos]);
        
        return dp[pos][target + 20000] = a+b;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        vec = nums;
        globalTarget = target;
        memset(dp, -1, sizeof dp);
        return solve(0, 0);
    }
};

/**
 * Solution using dp bottom up
 * 
 * Basically u start [0][nums[0]] = 1, since u can reach this value using nums[0]
 * for each transition, u'll get memo[i][j + nums[i] (future sum)] and memo[i][j - nums[i] (future sum)] += memo[i-1][j (currentSum)]
 * 
 * Same complexity
 */ 

class Solution {
public:
    int memo[21][40001];
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memo[0][20000 + nums[0]] += 1;
        memo[0][20000 - nums[0]] += 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j <= 40000; j++) {
                if(j + nums[i] >= 0 && j + nums[i] <= 40000 && memo[i-1][j] >= 1)
                    memo[i][j + nums[i]] += memo[i-1][j];
                if(j - nums[i] >= 0 && j - nums[i] <= 40000 && memo[i-1][j] >= 1)
                    memo[i][j - nums[i]] += memo[i-1][j];
            }
        }    
        
        
        return memo[nums.size() - 1][20000 + target];
    }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}