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
 * https://leetcode.com/problems/sliding-window-maximum/
 * 
 * normal two pointers to check each window and for each window
 * store the current numbers in addition if ur frequency
 * when move the first pointer, if the current frequency is 0, then
 * just remove it from set.
 * 
 * another thing is, after move a window, just get the rbegin() from the set
 * to get the max number
 * 
 * Complexity time: n log n
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int a = 0, b = 0;
        vector<int> ans;
        
        set<int> aux;
        unordered_map<int, int> qt;
        
        while(a < nums.size() && b < nums.size()) {
            while(b < nums.size() && b < a + k) {
                qt[nums[b]]++;
                aux.insert(nums[b]);
                b++;
            }
            
            int number = *aux.rbegin(); 
            ans.push_back(number);
            
            qt[nums[a]]--;
            if(qt[nums[a]] == 0) aux.erase(nums[a]);
            a++;
        }
        return ans;
    }
};

/**
 * This solution is better because runs in linear time
 * 
 * Basically u can use a deque to put the idxs and:
 * 1 - check if the leftmost idx is <= i - k (if yes, pop it because will be out of the window)
 * 2 - keep removing all rightmost idxs that are < than the current number
 * 3 - put the current idx there
 * 4 - update the answer
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        
        /**
        Put the idxs into the deque and check if 
        there's a index < i
        */
        for(int i = 0; i < nums.size(); i++) {
            if(!q.empty() && q.front() <= i - k) q.pop_front();   
            
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            
            q.push_back(i);
            
            if(i >= k - 1)
                ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}