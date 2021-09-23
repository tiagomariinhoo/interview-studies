#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/subarray-sum-equals-k/submissions/

int solution(vector<int> nums, int k) {

  int ans = 0, sum = 0;
  map<int, int> prevSum;

  prevSum[0] = 1;
  for(auto i : nums) {
    sum += i;

    // if(sum == k) ans++;

    // if(prevSum.find(sum - k) != prevSum.end()) {
      ans += (prevSum[sum - k]);
    // }

    prevSum[sum - k]++;
    prevSum[sum]++;
  }


  return ans;

}

int main() {

  vector<int> nums = {1, 1, 1};
  cout << solution(nums, 2) << endl;

  return 0;
}