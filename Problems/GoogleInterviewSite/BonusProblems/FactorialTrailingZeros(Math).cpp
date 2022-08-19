#include <bits/stdc++.h>
using namespace std;

/**
 * hhttps://leetcode.com/problems/factorial-trailing-zeroes/submissions/
 * 
 * A fun fact about this problem is:
 * To count trailing zeros, u just need to get the number and keep dividing by 10.
 * 10 consists of two prime factors: 2 * 5
 * Then, u basically need to count how many times the number N can be divided
 * by 2 and 5.
 * 
 * Another thing is, using N! can generate an overflow, then u just need to
 * use each number of the multiplication:
 * 1 * 2 * 3 * 4 * 5 ... * n
 * Just trying to divide each one of them per 2 and 5 to count the number of factors
 * 
 * The answer will be the min(x, y) where 2^x and 5^y
 */ 

class Solution {
public:
    int trailingZeroes(int n) {
        if(n <= 1) return 0;
        
        long long int current = 1;
        long long int ans = 0;
        long long int aux = 1;
        
        map<int, int> qt;
        
        for(int i=1;i<=n;i++) {
            int aux = i;
            
            
            while(aux%5 == 0) {
                aux /= 5;
                qt[5]++;
            }
            
            while(aux%2 == 0) {
                aux /= 2;
                qt[2]++;
            }
        }
        
        return min(qt[2], qt[5]);
    }
};

    

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}