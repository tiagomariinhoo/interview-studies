class Solution {
public:
    vector<vector<int>> ans;

    /*
        Simple problem to generate all permutations
        Just following this idea, swapping all indexes as possible

        Permutation algorithm runs in N! Complexity Time
    */

    void solve(int idx, vector<int> &nums) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return ;
        }

        solve(idx + 1, nums);

        for (int i = idx + 1; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            solve(idx + 1, nums);
            swap(nums[i], nums[idx]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};