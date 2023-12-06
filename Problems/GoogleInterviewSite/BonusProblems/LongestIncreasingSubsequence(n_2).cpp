class Solution {
public:
    /**
        It can be solved in N² with linear auxiliary space

        There are some different solutions for this problem. Starting from the Naive one:
        - 2^N solution, choosing pick up the number or not, like knapsack
        - N log N but 4 * (maxValue) auxiliary space, then if there are large numbers, it will be really bad. Basically this solution works by using a Segment Tree, you just need to iterate through the array and keep updating the seg tree with that number. Query max(0, currentNumber), get the max LIS before it, and update the current with MaxBeforeList + 1.

        - Following a similar approach from using Seg Tree, we can solve this problem in N² with linear auxiliary space. You just need to assign 1 (current LIS) for all numbers and keep iterating from 0..i, checking the maximum LIS for each one of them.
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ar(nums.size());
        int ans = 1;

        for (int i = 0; i < nums.size(); i++) ar[i] = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    ar[i] = max(ar[i], ar[j] + 1);
                    ans = max(ans, ar[i]);
                }
            }
        }

        return ans;
    }
};