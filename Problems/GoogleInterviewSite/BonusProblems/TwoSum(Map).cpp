#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/two-sum/
 * 
 * Pretty easy problem, just need to store the idx for each value
 * and check if there is (target - current[i]) idx 
 * 
 * Can be solved in Linear Complexity time using unordered_map
 */ 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbers;
        for(int i = 0; i < nums.size(); i++) {
            numbers[nums[i]] = (i + 1);
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int idx = 0;
            idx = numbers[target - nums[i]];
            if(idx != 0 && (idx - 1) != i) {
                ans.push_back(i);
                ans.push_back(idx - 1);
                break;
            }
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}