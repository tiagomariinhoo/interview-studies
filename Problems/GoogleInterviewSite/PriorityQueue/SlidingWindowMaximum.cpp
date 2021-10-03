#include <bits/stdc++.h>

using namespace std;

/**
 * HARD PROBLEM
 * https://leetcode.com/problems/sliding-window-maximum/submissions/
 * 
 * Just loop through the window in array and check 
 * the maximum value for each window
 * 
 * My solution used Two Pointers + Map + Priority Queue
 * 
 * Two pointers can runs in linear time O (n)
 * My map can store the values in O (log N), its also
 * possible to optimize for O (1) for store the values
 * 
 * My priority queue can store the elements in Log N
 * 
 * So, I just store my elements in the priority queue
 * for always get the maximum value for each window
 * and after this, I remove from my priority queue
 * all values that I dont have it anymore in my window
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> qt;
        priority_queue<int> pq;
        vector<int> answer;
        
        int a = 0, b = 0;
        while(a < nums.size() - k + 1) {
            while(b < a + k && a < nums.size()) {
                qt[nums[b]]++;
                pq.push(nums[b]);
                b++;
            }
            
            while(qt[pq.top()] == 0) {
                pq.pop();
            }
            
            answer.push_back(pq.top());
            qt[nums[a]]--;
            a++;
        }
        
        return answer;
    }
};

int main() {


  return 0;
}