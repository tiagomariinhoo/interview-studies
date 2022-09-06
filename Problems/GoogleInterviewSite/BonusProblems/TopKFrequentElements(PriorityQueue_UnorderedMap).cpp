#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/top-k-frequent-elements/submissions/
 * 
 * The point here is that we can store the elements frequency
 * into an unordered map that will takes constant time
 * 
 * After that we can use a priority queue to store the
 * pair of numbers in Log N
 * 
 * Basically the solution takes linear time
 */ 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> qt;
        
        //Linear Time
        for(auto i : nums) {
            qt[i]++;
        }
        
        priority_queue<pair<int, int> > pq;
        
        //Log N to insert
        for(auto i : qt) {
            pq.push({i.second, i.first});
        }
        
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};    

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}