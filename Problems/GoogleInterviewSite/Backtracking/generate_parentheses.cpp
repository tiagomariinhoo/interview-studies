#include <bits/stdc++.h>
using namespace std;

/**
 * Like the generate subsets problem
 * This problem can runs in N * 2 ˆ N,
 * 
 * Where 2 ˆ N is the recursion time
 * And N is because you need to push all strings
 * into the vector
 */ 

class Solution {
public:
    vector<string> answer;
    int globalN;
    
    void solve(string s, int left, int right) {
        if(left == globalN && right == globalN) {
            answer.push_back(s);
            return ;
        }
        
        if(left < globalN) {
            solve(s + '(', left + 1, right);
        }
        
        if(right < left) {
            solve(s + ')', left, right + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        globalN = n;
        solve("", 0, 0);
        return answer;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}