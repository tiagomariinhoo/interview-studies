#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/substring-with-largest-variance/submissions/
 * 
 * Can be solved in O (26 * 26 * N)
 * 
 * Basically just need to run Kadane for each pair of characters
 * 
 * Suppose that for character i u will change for 1 and
 * for character j u will change for -1
 * 
 * Run Kadane storing the numbers of current i and j into the sum
 * because it's necessary have at least one char i and one char j
 * 
 * After that, just updtate the answer
 */ 

class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        map<char, int> qt;
        for(auto i : s) qt[i]++;
        
        for(char i = 'a'; i <= 'z'; i++) {
            for(char j = 'a'; j <= 'z'; j++) {
                if(!qt[i] || !qt[j] || i == j) continue;
                vector<int> aux;
                
                for(auto k : s) {
                    if(k == i) {
                        aux.push_back(1);
                    } else if(k == j) {
                        aux.push_back(-1);
                    }
                }
                
                int sum = 0;
                
                int a = 0, b = 0;
                for(auto k : aux) {
                    if(k == 1) {
                        a++;
                    } else {
                        b++;
                    }
                    sum += k;
                    
                    if(sum < 0) {
                        a = 0, b = 0;
                        sum = 0;
                    } else {
                        if(a && b) {
                            ans = max({ans, sum, 0});
                        } else if(a && !b) {
                            ans = max({ans, sum - 1, 0});
                        }
                    }
                    
                }
            }
        }
        
        return ans;
    }
};

int main() {

  return 0;
}