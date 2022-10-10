#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/task-scheduler/submissions/
 * 
 * First u need to store all frequencies for each letter
 * 
 * After that, u need to prioritize the letter with more qt
 * 
 * Can be solved in O(26 * N) where N is the sum of all frequencies
 */ 
class Solution {
public:
    int letters[27];
    int lastTime[27];
    
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        int ans = 0;
        int qt = tasks.size();
        
        const int aa = -101010;
        
        for(int i = 'A'; i <= 'Z'; i++) lastTime[i - 'A'] = aa;
        
        for(auto i : tasks) letters[i - 'A']++;
        
        while(qt) {
            int current = -1;
            int aux = aa;
            int currentQt = 0;
            
            for(int i = 'A'; i <= 'Z'; i++) {
                int c = i - 'A';
                if(letters[c] > 0) {
                    if(lastTime[c] == aa) {
                        if(letters[c] > currentQt) {
                            current = c;
                            currentQt = letters[c];
                            aux = lastTime[c];
                        }
                    } else {
                        if(ans - lastTime[c] > n && letters[c] > currentQt) {
                            aux = lastTime[c];
                            current = c;
                            currentQt = letters[c];
                        }
                    }
                    
                }
            }
            
            if(ans - aux > n && current != -1) {
                lastTime[current] = ans;
                letters[current]--;
                qt--;
            }
            
            ans++;
        }
        
        return ans;
    }
};

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  maxArea()
  
  return 0;
}