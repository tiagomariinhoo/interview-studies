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

class Solution {
public:
    unordered_map<int, int> freq;
    // Since the follow up was makes a solution better than N log N
    /**
        This solution takes Linear Time but it uses Linear space time
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // Linear time, since we're using unordered_map that takes constant time to store/get/remove
        for (auto i : nums) {
            freq[i]++;
        }

        unordered_map<int, queue<int>> aux;

        // Even we having a queue here, for unordered map using primitive data, it takes O(1)
        // and to push an element into the queue, it also takes O(1)
        for (auto i : freq) {
            aux[i.second].push(i.first);
        } 
        vector<int> ans;

        // linear time since we're using N elements always
        for (int i = n; i >= 0; i--) {
            if (aux[i].size() > 0) { // To get the element from here, it's also O(1)
                while (k && !aux[i].empty()) {
                    ans.push_back(aux[i].front());
                    aux[i].pop();
                    k--;
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    /**
    Solution that runs in N Log K

    One important point here is that N log K is always less than N log N

    If k = N, the code would solve it in Linear time

    Since we're using a set with pair (primitive int), that still takes log K to insert
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        set<pair<int, int> > aux;
        vector<int> ans;

        for (auto i : nums) {
            freq[i]++;
        }

        for (auto i : nums) {
            if (aux.size() < k) {
                aux.insert({freq[i], i});
            } else if (aux.size() == k) {
                if (aux.find({freq[i], i}) == aux.end() && freq[i] > (*aux.begin()).first) {
                    aux.erase(aux.begin());
                    aux.insert({freq[i], i});
                }
            }
        }

        for (auto i : aux) {
            ans.push_back(i.second);
        }

        return ans;
    }
};