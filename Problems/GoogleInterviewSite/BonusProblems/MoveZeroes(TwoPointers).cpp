class Solution {
public:
    /**
        This problem can be solved in linear time using constant auxiliary space

        By using two pointers, we just need to use the left pointer to get the zeros and the right pointer to get the numbers different from zeroes. Everytime that we find a zero from the left pointer, we just need to swap them
    */
    void moveZeroes(vector<int>& nums) {
        int a = 0, b = 1;
        while (a < nums.size()) {
            if (nums[a] == 0) {
                if (b <= a) b = a + 1;
                while (b < nums.size() - 1 and nums[b] == 0) b++;
                if (b < nums.size() and nums[b] != 0) {
                    swap(nums[a], nums[b]);
                }
                a++;
            } else {
                a++;
            }

            if (b <= a) b = a + 1;
        }
    }
};