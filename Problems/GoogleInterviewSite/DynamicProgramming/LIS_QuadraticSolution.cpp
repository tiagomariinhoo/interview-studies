#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/longest-increasing-subsequence/
 * 
 * First of all, it's important to know about LCS (longest common subsequence)
 * https://www.youtube.com/watch?v=NnD96abizww&ab_channel=TusharRoy-CodingMadeSimple
 * 
 * Basically if u have two strings: "abcdaf" and "acbcf", the LCS is:
 * abcf
 * 
 * For that, we can just use the first vector with numbers to create another vector
 * using the sorted unique numbers and find the LCS
 * 
 * This problem can be solved in quadratic time O(n²)
 */ 

int memo[2501][2501];
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sortedNums;
        set<int> aux;
        vector<int> vec2;
        vec2.push_back(-1);
        for(auto i : nums) {
            vec2.push_back(i);
            aux.insert(i);
        }
        nums = vec2;
        sortedNums.push_back(-1);
        for(auto i : aux) sortedNums.push_back(i);

        
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 1; j < sortedNums.size(); j++) {
                if(nums[i] != sortedNums[j]) {
                    memo[i][j] = max({
                        memo[max(i-1, 0)][j],
                        memo[i][max(j-1, 0)],
                    });
                } else {
                    memo[i][j] = max({
                        memo[max(i-1, 0)][j],
                        memo[i][max(j-1, 0)],
                        memo[max(i-1, 0)][max(j-1, 0)] + 1,
                    });
                }
            }
        }

        
        return memo[nums.size() - 1][sortedNums.size() - 1];        
    }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> vec = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << lengthOfLIS(vec) << endl;

  return 0;
}