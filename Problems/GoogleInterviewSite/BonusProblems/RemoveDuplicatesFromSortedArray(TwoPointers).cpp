#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
 * 
 * Just a two pointer problem that can be solved in linear time
 * 
 */ 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int a = 0, b = 0;
        
        while(a < nums.size()) {
            if(b == nums.size()) break;
            
            while(b < nums.size()) {
                if(nums[b] != nums[a]) {
                    a++;
                    nums[a] = nums[b];
                    break;
                }
                b++;
            }
            
            count++;
            
        }
        
        cout << count << endl;
        
        return count;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}