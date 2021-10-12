#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/

class Solution {
public:
    
    int lowerBound(vector<int> nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if(nums[r] != target) return -1;
        
        return r;
    }
    
    int upperBound(vector<int> nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        
        if(nums[l] != target) return -1;
        
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            vector<int> ans = {-1, -1};
            return ans;
        }
        
        vector<int> ans = {lowerBound(nums, target), upperBound(nums, target)};
        
        return ans;
    }
};

int main() {

  return 0;
}