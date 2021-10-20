#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * https://leetcode.com/problems/subsets/solution/
 * 
 * This solution can runs in exponential time n*2ˆn
 * where N is the number of elements in globalNums
 * 
 * Basically the solution is the following
 * 
 * I have two options on my recursion, the first one
 * will pass the vector without the current element
 * 
 * The second option will pass the vector with the current element
 * inside. Doing this, I have the following:
 * 
 * 0 1 2 3
 * 0
 * 1
 * 2
 * 3
 * 0 1
 * 0 2
 * 0 3
 * 1 2...
 * 
 * Just the recursion takes 2ˆn
 * But if we add the time that the algorithms takes to
 * pushing a vector inside another, this will take linear time
 * Then the complexity time at the final of the algorithm is: N * 2 ^ N
 */ 

class Solution {
public:
    vector<vector<int>> answer;
    vector<int> globalNums;
    
    void solve(vector<int> vec, int idx) {
        if(idx == globalNums.size()) {
            answer.push_back(vec);
            return ;
        }
        
        solve(vec, idx + 1);
        vec.push_back(globalNums[idx]);
        solve(vec, idx + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        globalNums = nums;
        vector<int> vec;
        solve(vec, 0);
        
        return answer;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}