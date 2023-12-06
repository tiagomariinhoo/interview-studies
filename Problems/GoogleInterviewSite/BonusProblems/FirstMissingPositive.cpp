class Solution {
public:
    /**
    There's a similar problem where u need to find duplicate numbers and u can use the same theory as here
    There u can use the own elements to invert the signal for the number just to mark as visited.
    Here you need to keep swaping numbers until find the correct place for each one, but always being careful
    if the current number is >= 1 and is <= nums.size() (since are the numbers that we're interested)

    That makes our solution runs in linear time and takes constant auxiliary space
    */
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (1) {
                if (nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= nums.size()) {
                    if (nums[i] == nums[nums[i] - 1]) break;
                    swap(nums[i], nums[nums[i] - 1]);
                } else break;
            }
        }

        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ans) ans++;
        }

        return ans;
    }
};