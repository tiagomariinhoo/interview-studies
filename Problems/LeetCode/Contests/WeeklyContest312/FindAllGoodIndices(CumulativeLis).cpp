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
 * https://leetcode.com/contest/weekly-contest-312/problems/find-all-good-indices/
 * 
 * The problem was just to find the good indices, where:
 *  - The k elements that are just before the index i are in non-increasing order.
 *  - The k elements that are just after the index i are in non-decreasing order.
 * 
 * Then the solution was just store the cumulative LIS for each side
 * And for each index, just check if the cumulative LIS for i + 1 and i - 1, is >= k
 * the solution runs in linear time
 */
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> dec;
        vector<int> inc;
        
        dec.push_back(1);
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i - 1]) {
                dec.push_back(dec[dec.size() - 1] + 1);
            } else dec.push_back(1);
        }
        
        inc.push_back(1);
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] <= nums[i + 1]) {
                inc.push_back(inc[inc.size() - 1] + 1);
            } else inc.push_back(1);
        }
        
        reverse(inc.begin(), inc.end());
        
        vector<int> ans;
        
        for(int i = 1; i < nums.size() - 1; i++) {
            if(i > 0 && i < nums.size() - 1 && inc[i + 1] >= k && dec[i - 1] >= k) {
                ans.push_back(i);
            } else {
                if(i == 0 && i < nums.size() - 1 && inc[i + 1] >= k) ans.push_back(i);
                else if(i == nums.size() - 1 && dec[i - 1] >= k) ans.push_back(i);
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