#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/subsets/
 * 
 * The trick for this problem beyond the mask
 * is use +10 to include the negative numbers
 * and -10 when put into the vector answer
 * 
 * This problem can be solved in
 * n * 2^n
 * 
 * without dynamic programming
 * 
 */ 

class Solution {
public:
    vector<int> vec;
    vector<vector<int> > ans;
    
    void backtracking(int pos, int mask) {
        if(pos == vec.size()) {
            vector<int> aux;
            for(int i = 0; i <= 20; i++) {
                if(mask & (1 << i)) {
                    aux.push_back(i - 10);
                }
            }

            ans.push_back(aux);
            
            return ;
        }
        
        
        backtracking(pos + 1, mask);
        backtracking(pos + 1, mask | (1 << (vec[pos] + 10)));
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vec = nums;
        backtracking(0, 0);
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}