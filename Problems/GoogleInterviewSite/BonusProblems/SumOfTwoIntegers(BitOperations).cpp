#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/sum-of-two-integers/
 * 
 * The challenge for this problem is that sum two integers without use + or - directly
 * 
 * Basically u need to deal with some corner cases
 * If a == 0, return b / b == 0, return a
 * 
 * If both numbers a and b are < 0, then u can deal with them as positive numbers (just multiply by -1 at the end)
 * 
 * After this, just need to transform those numbers in binary and keep doing sum for each one of them
 * 
 * 11101
 * 10010
 * 
 * 1 + 0 = 1
 * 0 + 0 = 0
 * 1 + 1 = 0 (rem = 1 and use it in the next sum)
 */ 

class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0) return b;
        else if(b == 0) return a;
        
        bool at = false;
        if(a < 0 && b < 0) {
            at = true;
            a *= -1;
            b *= -1;
        }
        vector<int> vecA;
        vector<int> vecB;
        
        for(int i = 0; i < 30; i++) {
            if(a & (1 << i)) {
                vecA.push_back(1);
            } else {
                vecA.push_back(0);
            }
            
            if(b & (1 << i)) {
                vecB.push_back(1);
            } else {
                vecB.push_back(0);
            }
        }
        
        vector<int> binaryAns;
        
        int rem = 0;
        
        for(int i = 0 ; i < vecA.size(); i++) {
            int sum = vecA[i] + vecB[i];
            
            if(sum == 2) {
                if(rem == 1)
                    binaryAns.push_back(1);
                else binaryAns.push_back(0);
                rem = 1;
            } else if(sum == 1) {
                if(rem == 1) {
                    binaryAns.push_back(0);
                } else {
                    binaryAns.push_back(1);
                }
            } else {
                if(rem == 1)
                    binaryAns.push_back(1);
                else binaryAns.push_back(0);
                
                rem = 0;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < binaryAns.size(); i++) {
            if(binaryAns[i] == 1) {
                ans += pow(2, i);
            }    
        }
    
        if(at) ans *= -1;
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}