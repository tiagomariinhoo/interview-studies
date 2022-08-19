#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/sort-colors/submissions/
 * 
 * Easy problem, just count the number of 0, 1 and 2
 * Linear time
 */ 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> qt;
        for(auto i : nums) {
            qt[i]++;
        }
        

        for(int i = 0; i < nums.size(); i++) {
            if(qt[0]) {
                nums[i] = 0;
                qt[0]--;
            } else if(qt[1]) {
                nums[i] = 1;
                qt[1]--;
            } else if(qt[2]) {
                nums[i] = 2;
                qt[2]--;
            }
            
        }
    }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}