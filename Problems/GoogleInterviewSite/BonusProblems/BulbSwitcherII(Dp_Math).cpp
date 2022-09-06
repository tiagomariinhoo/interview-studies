#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/bulb-switcher-ii/submissions/
 * 
 * For this problem it's important to notice that we will have
 * at most 8 possibilities
 * 000
 * 111
 * 101
 * 001
 * 010
 * 100
 * 110
 * 011
 * The others n >= 4, will follow the same 
 * cycle, then we just need to make a dfs testing all those possibilities
 * 
 */ 

class Solution {
public:
    
    /**
    I think I can use a range like:
        1 2 3 4 5 6 7 
    */
    int current = 0;
    int memo[300][1001];
    int globalPress;
    set<int> ans;
    
    void solve(int mask, int press, int last) {
        
        
        if(press == 0) {
            ans.insert(mask);
            return ;
        }
        
        if(memo[mask][press] != -1) return;
        
        memo[mask][press] = 1;
        
            int auxMask = mask;
            for(int i = 0; i <= current; i++) {
                if((i + 1)%2 == 0) {
                    auxMask ^= (1 << i);
                }
            }    
            solve(auxMask, press - 1, 2);
        auxMask = mask;
            for(int i = 0; i <= current; i++) {
                if((i + 1)%2 != 0) {
                    auxMask ^= (1 << i);
                }
            }   
            solve(auxMask, press - 1, 3);
        auxMask = mask;
            for(int i = 0; i*3 <= current; i++) {
                auxMask ^= (1 << (i*3));
            }
            solve(auxMask, press - 1, 4);
        auxMask = mask;
            for(int i=0;i<=current;i++) {
                auxMask ^= (1 << i);
            }
            solve(auxMask, press - 1, 1);
    }
    
    int flipLights(int n, int presses) {
        if(presses == 0) return 1;
        current = min(n, 8) - 1;
        globalPress = presses;
        memset(memo, -1, sizeof memo);
        int mask = pow(2, min(n, 8)) - 1;
        solve(mask, presses, 1);
        solve(mask, presses, 2);
        solve(mask, presses, 3);
        solve(mask, presses, 4);
        
        
        return ans.size();
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}