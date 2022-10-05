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
 * https://leetcode.com/contest/weekly-contest-310/problems/most-frequent-even-element/
 * 
 * Just count the numbers and store the answer
 * Linear time
 */

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> count;
        
        int ans = -1;
        
        int qt = 0;
        
        for(auto i : nums) {
            if(i%2 == 0) {
                count[i]++;
                if(count[i] > qt) {
                    qt = count[i];
                    ans = i;
                } else if(count[i] == qt && i < ans) {
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}