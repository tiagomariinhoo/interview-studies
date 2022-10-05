#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(1e5 + 5)
#define MAXL 20
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 9)
#define MOD2 (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, lli> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

/**
 * https://leetcode.com/contest/weekly-contest-307/problems/largest-palindromic-number/
 * 
 * Can be solved just using queue starting for the largest numbers
 * Putting pair of numbers in each side and at the end,
 * just try to put the highest number in the middle
 * 
 * Just be careful with leading zeroes corner case
 */

class Solution {
public:
    string largestPalindromic(string num) {
        string ans = "";
        queue<char> q[10];
        
        for(int i = 0; i < num.size(); i++) {
            int n = num[i] - '0';
            q[n].push(num[i]);
        }
        
        deque<char> leftAns, rightAns;
        bool at = false;
        for(int i = '9'; i >= '0'; i--) {
            
            while(q[i - '0'].size() >= 2) {
                if(i == '0' && leftAns.size() > 0) {
                    leftAns.push_back(i);
                    rightAns.push_front(i);
                    q[i - '0'].pop();
                    q[i - '0'].pop();
                } else if(i != '0') {
                    leftAns.push_back(i);
                    rightAns.push_front(i);
                    q[i - '0'].pop();
                    q[i - '0'].pop();
                } else break;
            } 
        }
        
        for(int i = '9'; i >= '0'; i--) {
            if(q[i - '0'].size() >= 1) {
                if(i == '0') {
                    if(leftAns.size() >= 0) {
                        leftAns.push_back(i);
                        break;
                    }
                } else {
                    leftAns.push_back(i);
                    break;
                }
            }
        }
        
        
        for(int i = 0; i < leftAns.size(); i++) ans += leftAns[i];
        for(int i = 0; i < rightAns.size(); i++) ans += rightAns[i];
        
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}