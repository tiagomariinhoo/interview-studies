#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/3sum/submissions/
 * 
 *
 */ 

// Binary Search Solution
/**
 * n² log n
 * Picking up the third value using binary search
 */ 
class Solution {
public:
    
    int findNumber(int pos, vector<int> &nums, int target) {
        if(pos >= nums.size()) return INT_MAX;
        
        int l = pos;
        int r = nums.size() - 1;
        
        while(l < r) {
            int m = l + (r - l) / 2; // I don't want to have l = m to avoid infinite loop
            if(nums[m] < target) l = m + 1;
            else r = m;
        }
        
        if(nums[l] == target) return target;
        return INT_MAX;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        
        int ult = INT_MAX;
        int ult2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == ult) continue;
            ult = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] == ult2) continue;
                ult2 = nums[j];
                
                int currentSum = nums[i] + nums[j];
                int thirdNumber = findNumber(j + 1, nums, currentSum * - 1);
                
                if(thirdNumber != INT_MAX) {
                    vector<int> aux;
                    aux.push_back(nums[i]);
                    aux.push_back(nums[j]);
                    aux.push_back(thirdNumber);
                    
                    ans.push_back(aux);
                }
            }
        }
        
        return ans;
    }
};

// n² solution using array
/**
 * Looping through the second value and checking if there's a element
 * in the next values such as -(nums[i] + nums[j])
 * Always updating the value in the array
 */ 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int> > ans;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int vis[400001];
            memset(vis, 0, sizeof vis);
            int a = i + 1;
            for(int j = nums.size() - 1; j >= i + 2; j--) {
                vis[nums[j] + 200000]++;
            }
            while(a < nums.size() - 1) {
                if(vis[-(nums[a] + nums[i]) + 200000]) {
                    vector<int> aux = {nums[i], nums[a], -(nums[a] + nums[i])};
                    ans.push_back(aux);
                }
                
                a++;
                vis[nums[a] + 200000]--;
                
                while(a < nums.size() - 1 && nums[a] == nums[a - 1]) {
                    a++;
                    vis[nums[a] + 200000]--;
                }
            }
        }
        
        return ans;
    }
};

// n² solution using two pointers, fastest solution
/**
 * Same as previous idea but  for the second and third value,
 * i, j, k
 * Loop through i,
 * j = i + 1,
 * k = n - 1,
 * if the current sum is < 0, increase j
 * else, decrease k
 */ 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int> > ans;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int a = i + 1;
            int b = nums.size() - 1;
            while(a < b) {
                if(nums[i] + nums[a] + nums[b] > 0) {
                    b--;
                    continue;
                } else if(nums[i] + nums[a] + nums[b] < 0) {
                    a++;
                    continue;
                } else {
                    vector<int> aux = {nums[i], nums[a], nums[b]};
                    ans.push_back(aux);
                }
                
                a++;
                
                while(a < nums.size() - 1 && nums[a] == nums[a - 1]) {
                    a++;
                }
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