#include <bits/stdc++.h>

using namespace std;

/**
 * Just ust a priority queue that can store
 * just K elements. Get the pq.top()
 */

class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto i : matrix) {
            for(auto j : i) {
                pq.push(j);
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }
        
        return pq.top();
    }
};

int main() {

  return 0;
}