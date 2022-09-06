#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/counting-bits/submissions/
 * 
 * For each number, just count the bits
 * N * 32
 */ 

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            int aux = 0;
            for(int j = 0; j < 32; j++) {
                if(i & (1 << j)) aux++;
            }
            ans.push_back(aux);
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}