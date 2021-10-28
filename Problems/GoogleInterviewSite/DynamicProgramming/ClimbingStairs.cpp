#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/climbing-stairs/submissions/
 * 
 * Top Down solution
 */

class Solution {
public:
    int globalN;
    int memo[3][45];
    int solve(int op, int current) {
        if(current > globalN) return 0;
        if(current == globalN) return 1;
        
        if(memo[op][current] != -1) return memo[op][current];
        
        int a = solve(1, current + 1);
        int b = solve(2, current + 2);
        
        return memo[op][current] = a + b;
    }
    
    int climbStairs(int n) {
        globalN = n;
        
        memset(memo, -1, sizeof memo);
        
        int ans = solve(0, 0);
        
        return ans;
    }
    // Bottom up solution
    // int memo[50];
    //     memset(memo, 0, sizeof memo);
        
    //     memo[0] = 1;
    //     memo[1] = 1;
    //     for(int i=2;i<=n;i++) {
    //         memo[i] += (memo[i-1] + memo[i-2]);
    //     }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}