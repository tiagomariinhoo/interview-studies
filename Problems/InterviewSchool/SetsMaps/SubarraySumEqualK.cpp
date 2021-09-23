#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/subarray-sum-equals-k/submissions/

/**
 * Quadratic and simple solution
 * 
 * For each index, I can loop through my array until the end
 * and check if I can get a sum == k
 * 
 * Linear solution
 * 
 * In my loop, I can store the sum that I have currently
 * and check if I already stored a sum that: sum - k
 * 
 * This can be done because when u check if a sum: sum - k
 * was already calculated, this indicates that from my
 * current position, subtracting K from my sum, I can go
 * for a previous index, that will have sum - k.
 */ 

int solution(vector<int> nums, int k) {

  int sum = 0, ans = 0;
  map<int, int> storedSums;

  storedSums[0] = 1;

  for(auto i : nums) {
    sum += i;

    ans += storedSums[sum - k];

    storedSums[sum]++;
  }

  return ans;
}

int main() {

  vector<int> nums = {1, 1, 1};
  cout << solution(nums, 2) << endl;

  return 0;
}