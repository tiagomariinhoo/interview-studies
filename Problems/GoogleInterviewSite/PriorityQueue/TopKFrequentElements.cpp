#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> qt;
        
        //O (1) to store elements and the frequence
        for(auto i : nums) {
            qt[i]++;
        }
        
        priority_queue<pair<int, int> > pq;
        
        // Log N to store each pair: frequence, element
        // and sort by the first element
        for(auto i : qt) {
            pq.push({i.second, i.first});
        }
        
        vector<int> answer;
        while(k--) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        
        return answer;
    }
};

int main() {

  return 0;
}