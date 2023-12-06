class Solution {
public:
/**
 * https://leetcode.com/problems/maximum-product-subarray/description/
 * 
    We just need to split the intervals through the Zeroes
    We can move the left pointer until find a zero (multiplying each number) and move the right pointer later
    because if there's a case where we have a odd number of odd numbers in the interval, when moving only either the
    left pointer or right pointer, we will have a case with even numbers of odd numbers and it will be the maximum answer
    for that interval

    The solution works in linear time
*/
    int maxProduct(vector<int>& nums) {
        int j = 0;
        int current = 0;
        int ans = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (current == 0) current = nums[i];
                else {
                    current *= nums[i];
                }
            } else {
                while (j < i - 1) {
                    current /= nums[j];
                    ans = max(ans, current);
                    j++;
                }
                current = 0;
                j = i + 1;
            }
            ans = max(ans, current);
        }

        while (j < nums.size() - 1) {
            if (nums[j] != 0 && nums[j] != nums.size() - 1)
                current /= nums[j];
            else break;
            ans = max(ans, current);
            j++;
        }

        return ans;
    }
};