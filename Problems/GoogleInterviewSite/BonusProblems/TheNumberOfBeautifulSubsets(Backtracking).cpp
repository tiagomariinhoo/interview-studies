class Solution {
public:
    /**
    That's a very interesting backtracking problem
    
    Can be solved in O(2^n) complexity time with O(N) space 
    
    We don't even need to sort, but following knapsack idea, 
    you just need to put the current element if there's no element - k and element + k,
    always updating the vis map (using reference for don't create a copy)
    */
    
    int ans;
    
    void dfs(int i, vector<int> &nums, int k, unordered_map<int, int> &vis) {
        if (i == nums.size()) {
            if (vis.size() > 0) {
                ans++;   
            }
            return ;
        }
        
        // Without pick up the current number
        dfs(i + 1, nums, k, vis);
        if (!vis[nums[i] - k] && !vis[nums[i] + k]) {
            vis[nums[i]]++;
            dfs(i + 1, nums, k, vis);
            vis[nums[i]]--;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> vis;
        dfs(0, nums, k, vis);
        
        return ans;
    }
};

class Solution {
public:
    /**
        Solution using knapsack idea but like a Dp with bitmask
        Runs in O(N) complexity time but takes O(2 ^ N) space
    */
    int memo[1 << 21];
    int ans = 0;

    int solve(int i, int mask, vector<int> &nums, int k) {
        if (i == nums.size()) {
            if (mask != 0)
                return 1;

            return 0;
        }
        

        if (memo[mask] != -1) return memo[mask];

        bool at = false;
        for (int j = 0; j < nums.size(); j++) {
            if (mask & (1 << j)) {
                if (abs(nums[i] - nums[j]) == k) {
                    at = true;
                }
            }
        }

        int a = 0;
        a += solve(i + 1, mask, nums, k);
        if (!at) {
            a += solve(i + 1, mask | (1 << i), nums, k);
        }

        return a;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        memset(memo, -1, sizeof memo);
        return solve(0, 0, nums, k);
    }
};