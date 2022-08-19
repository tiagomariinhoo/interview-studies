#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/hamming-distance/submissions/
 * 
 * Just need to check bit by bit
 * 
 */ 

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 0; i < 31; i++) {
            int bitX = x & (1 << i);
            int bitY = y & (1 << i);
            
            if(bitX ^ bitY) {
                ans++;
            }
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}