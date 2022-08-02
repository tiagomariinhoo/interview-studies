#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/base-7/submissions/
 * 
 * The same logic can be applie to convert the number
 * for any base.
 * 
 * Just need to imagine that the decimal number is
 * built by something like:
 * 
 * 100 -> decimal
 * 202 -> base 7
 * 
 * 100 = (2* 7^2 + 0* 7^1 + 2* 7^0);
 * 
 * Then, for any base, u can just
 * get the last digit using the remainder
 * and divide by the base
 * 
 * Keep appending the answer and reverse the answer
 * To deal with negative numbers, just need to apply
 * the -
 */ 

string convertToBase7(int num) {
        string ans = "";
        
        if(num < 0) {
            ans = "-" + (convertToBase7(num * -1));
            return ans;
        } else if(num == 0) {
            return "0";
        }
        
        while(num > 0) {
            int dig = (num%7);
            num /= 7;
            ans += (dig + '0');
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}