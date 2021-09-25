#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/top-k-frequent-elements/submissions/
 */ 

int solution(vector<int> nums, int k) {
  // O(1)
  unordered_map<int, int> qt;

  // O(n)
  for(auto i : nums) {
    qt[i]++;
  }  
  
  vector<pair<int, int> > vec;

  for(auto i : qt) {
    vec.push_back({i.second, i.first});
  }

  // N log N
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  vector<int> ans;

  for(int i=0;i<k;i++){
    ans.push_back(vec[i].second);
  }

  return ans;
}

int main() {

  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  
  cout << solution(nums, k) << endl;

  return 0;
}