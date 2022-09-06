#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/combination-sum/submissions/
 * 
 * Basically just do something like a knap to try all combinations
 * 
 * The complexity time is O(N^(m/t + 1))
 * N is the number of candidates
 * M is the smallest candidate among all the given integers
 * T is the target value
 * 
 * Makes sense, since I don't need to sum more than m/t times
 * 
 * Space Complexity
 * O(T/M)
 */ 

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    map<vector<int>, int> vis;
    int globalTarget;
    
    void solve(int pos, vector<int> aux, int currentSum) {
        if(currentSum == globalTarget && !vis[aux]) {
            vis[aux] = 1;
            
            for(auto i : aux) cout << i << " ";
            cout << endl;
            
            ans.push_back(aux);
            return ;
        }
        
        if(pos == vec.size()) return ;
        
            vector<int> aux2 = aux;
            for(int j = 1; j <= 500; j++) {
                if(currentSum + (j*vec[pos]) <= globalTarget) {
                    aux2.push_back(vec[pos]);
                    solve(pos + 1, aux2, currentSum + (j * vec[pos]));
                } else {
                    break;   
                }
            }
        
        solve(pos + 1, aux, currentSum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        globalTarget = target;
        vec = candidates;
        solve(0, vector<int>(), 0);
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}