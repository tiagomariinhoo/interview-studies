class Solution {
public:
    // Linear kadane for negative numbers too
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = -INT_MAX;

        for (auto i : nums) {
            sum += i;
            sum = max(sum, i);
            ans = max(ans, sum);
        }

        return ans;
    }
};

class Solution {
public:

    // Divide and conquer solution that takes N Log N
    int solve(int l, int r, vector<int> &nums) {
        if (l == r) return nums[l];
        else if(l > r) return 0;

        int mid = (l + r) / 2;
        int leftSum = 0, rightSum = 0;
        int currentSum = 0 ;

        for (int i = mid - 1; i >= l; i--) {
            currentSum += nums[i];
            leftSum = max(leftSum, currentSum);
        }

        currentSum = 0;

        for (int i = mid + 1; i <= r; i++) {
            currentSum += nums[i];
            rightSum = max(rightSum, currentSum);
        }

        return max({solve(l, mid, nums), solve(mid + 1, r, nums), leftSum + rightSum + nums[mid]});
    }

    int maxSubArray(vector<int>& nums) {

        return solve(0, nums.size() - 1, nums);
    }
};