// https://leetcode.com/problems/random-pick-index/submissions/
#include <bits/stdc++.h>

using namespace std;

class Solution {    
public:
    map<int, vector<int> > mp;

    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
          mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
      int value = mp[target].size();

      return mp[target][rand() % value];
    }
};

int main() {
  


  return 0;
}