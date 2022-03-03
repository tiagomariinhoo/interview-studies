#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
 * 
 * Try to view Dp as a Dag
 */


//Top down solution
class Solution {
public:
    vector<int> globalCost;
    int memo[1001];
    
    int solve(int idx, int current) {
        if(idx >= globalCost.size()) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        int a = solve(idx + 1, 1) + globalCost[idx];
        int b = solve(idx + 2, 2) + globalCost[idx];
        
        return memo[idx] = min(a,b);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        globalCost = cost;
        
        memset(memo, -1, sizeof memo);
        
        return min(solve(0, 0), solve(1, 0));
    }
};

// Bottom up solution
//  int dp[1001];
//     int minCostClimbingStairs(vector<int>& cost) {
// //         globalCost = cost;
        
// //         memset(memo, -1, sizeof memo);
        
        
//         memset(dp, INT_MAX, sizeof dp);
        
//         dp[0] = 0;
//         dp[1] = 0;
        
//         for(int i = 2; i <= cost.size(); i++) {
//             dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
//             cout << dp[i] << endl;
//             // cout << cost[i-1] << " -- " << cost[i-2] << endl;
//         }
        
    
//         // for(int i=0;i<=cost.size();i++) {
//         //     cout << i << " - " << dp[i] << endl;
//         // }
        
//         // return min(solve(0, 0), solve(1, 0));
//         return dp[cost.size()];
//     }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}