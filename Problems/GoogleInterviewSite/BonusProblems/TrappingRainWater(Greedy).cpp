class Solution {
public:
    /**
        Interesting problem and it can be solved in linear time using O(N) space

        The point here is that u just need to store the maxLeft height and maxRight height
        and check if the current height is smaller than both

        If it is, u just need to sum min(leftHeight, rightHeight) - height[i] into ur answer
    */
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int leftMax[n + 1], rightMax[n + 1];
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        for (int i = 1 ; i < n - 1; i++) {
            if (leftMax[i - 1] > height[i] && rightMax[i + 1] > height[i]) {
                ans += min(leftMax[i - 1], rightMax[i + 1]) - height[i];
            }
        }

        return ans;
    }
};