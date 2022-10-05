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
 * https://leetcode.com/problems/longest-subsequence-with-limited-sum/
 * 
 * 
 */

// Quadratic time solution
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());   
        vector<int> ans;
        
        for(auto query : queries) {
            int sum = 0;
            int qt = 0;
            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                qt++;
                if(sum > query) {
                    qt--;
                    break;
                }
            }
            ans.push_back(qt);
        }
        
        return ans;
    }
};

// Binary search solution in n log n
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());   
        
        vector<int> sum;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            sum.push_back(nums[i]);
            if(i > 0) sum[i] += sum[i - 1];
        }
        
        for(auto query : queries) {
            cout << query << endl;
            int l = 0, r = sum.size() - 1;
            while(l < r) {
                int mid = r - (r - l) / 2; // We want to avoid do: l = mid to don't get an infinite loop
                if(sum[mid] <= query) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if(sum[l] <= query) ans.push_back(l + 1);
            else ans.push_back(0);
        }
        
        return ans;
    }
};

// Online queries solution in n log n
class Solution {
public:
    // Online queries
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int> > newQueries;
        
        for(int i = 0; i < queries.size(); i++) {
            newQueries.push_back({queries[i], i});
        }
        
        sort(newQueries.begin(), newQueries.end());
        
        vector<int> ans(queries.size());
        
        int i = 0, j = 0;
        int sum = 0;
        
        while(j < newQueries.size()) {
            bool at = false;
            while(i < nums.size()) {
                sum += nums[i];
                if(sum > newQueries[j].first) {
                    sum -= nums[i];
                    if(nums[0] > newQueries[j].first)  ans[newQueries[j].second] = 0;
                    else ans[newQueries[j].second] = i;
                    
                    at = true;
                    break;
                }
                
                if(i < nums.size())
                    i++;
            }
            if(!at) {
                ans[newQueries[j].second] = i;
            }
            
            j++;
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}