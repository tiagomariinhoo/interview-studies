#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/single-number/submissions/
 * 
 * Just use xor to keep the single number up
 * 
 */ 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number = 0;
        for(auto i : nums) {
            number ^= i;
        }
        
        return number;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}