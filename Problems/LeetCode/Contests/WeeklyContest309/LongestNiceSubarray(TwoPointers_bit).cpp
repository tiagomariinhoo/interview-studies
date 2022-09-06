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
 * https://leetcode.com/contest/weekly-contest-309/problems/longest-nice-subarray/
 * 
 * Find the longest nice subarray, where all AND elements are zero
 * 
 * Can be solved using Two Pointers technique where u just need to keep adding a numbers
 * while it's possible, if not, u can move the left pointer removing the current number
 * 
 * Linear time
 */

class Solution {
public:
    // Test a two pointers solution, try to put a number and set a mask, if the bit is already there, then keep moving the first pointer until
    // The mask works
    
    bool can(int num, int mask) {
        for(int i = 0; i < 32; i++) {
            if((mask & (1 << i)) && (num & (1 << i))) return false;
        }
        
        return true;
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        int a = 0, b = 0;
        int ans = 1;
        int mask = nums[a];
        while(a < nums.size()) {
            if(a >= b) b = a + 1;
            
            while(b < nums.size()) {
                if(can(nums[b], mask)) {
                    mask |= nums[b];
                    ans = max(ans, b - a + 1);
                } else {
                    break;
                }
                
                b++;
            }
            
            mask &= (~nums[a]);
            a++;
            if(a < nums.size())
            mask |= nums[a];
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}