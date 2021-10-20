#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> globalNums;
    vector<vector<int> > answer;
    
    void solve(vector<int> vec, int l) {
        if(l == vec.size()) {
            answer.push_back(vec);
            return ;
        }
        
        for(int i = l; i < vec.size(); i++) {
            swap(vec[l], vec[i]);
            solve(vec, l + 1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        
        return answer;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}