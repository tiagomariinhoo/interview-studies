#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/4sum-ii/submissions/
 * 
 * The first solution that I can try here, is
 * a nˆ4 solution. Basically, looping through 
 * the everyone inside each other.
 * 
 * The point is, that we can break in 2 pairs of arrays
 * 
 * Lets suppose that we have the array A, B, C and D.
 * 
 * The tuples can be made by:
 * a + b = - (c + d)
 * Where a, b, c and d, are indexes from each one of them
 * 
 * So I can store all sums a + b
 * And when iterate over array C and D, I can check 
 * if had a sum (a + b) = - (c + d)
 */ 

int solution(vector<int> nums1, vector<int> nums2, vector<int> nums3, vector<int> nums4) {

  int ans = 0;

  map<int, int> storedSums;
  
  for(auto i : nums1) {
    int sum = i;
    for(auto j : nums2) {
      sum += j;
      storedSums[sum]++;
      sum -= j;
    }
  }

  for(auto i  : nums3) {
    int sum = i;
    for(auto j : nums4) {
      sum += j;
      ans += storedSums[-sum];
      sum -=j;
    }
  }

  return ans;
}

int main() {

  vector<int> nums = {1, 2};
  vector<int> nums2 = {-2, -1};
  vector<int> nums3 = {-1, 2};
  vector<int> nums4 = {0, 2};
  cout << solution(nums, nums2, nums3, nums4) << endl;

  return 0;
}