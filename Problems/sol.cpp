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

     return 0;   
    }
};

int main() {
  


  return 0;
}