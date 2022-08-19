#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/number-of-1-bits/submissions/
 * 
 * Just using bit operations to count 1
 */ 

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i <= 31; i++) {
            if(n & (1 << i)) ans++;
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}