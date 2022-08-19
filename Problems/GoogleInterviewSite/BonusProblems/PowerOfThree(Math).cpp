#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/power-of-three/solution/
 * 
 * Just looping through the math operation
 * 
 * There are also more interesting solutions
 */ 

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        
        for(int i=0;i<=30;i++) {
            long long int value = pow(3, i);
            if(value == n) return true;
        }
        
        return false;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}