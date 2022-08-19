#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/powx-n/submissions/
 * 
 * Classic problem to solve Pow(x, n)
 * 
 * https://youtu.be/-3Lt-EwR_Hw
 * 
 * The solution below solve the problem in log(n) 
 * Since we can use the property:
 * 2^4 = (2^2) * (2^2)
 * 
 * Just need to be careful when n < 0
 */ 


class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        
        long long int nn = n;
        
        bool at = false;
        if(nn < 0) {
            at = true;
            nn *= -1;
        }
        if(nn == 0) return result;
        
        while(nn > 0) {
            if(nn % 2 == 0) {
                x *= x;
                nn/= 2;
            } else {
                result *= x;
                nn--;
            }
        }
        
        if(at) {
            return (double) 1 / result;
        }
    
        
        return result;
    }
        
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}