class Solution {
public:
    /**
        There's a very simple and direct solution here. Store the frequency in a unordered_map (since the values may be negative) and get the most frequent one.

        The best solution that solves the problem in O(N) with O(1) space, uses Moore Voting Algorithm (https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)
        Basically, the problem ensures that the most frequent element will appear >= n/2 times.
        Then we can assume that:
        1 - Initialize a candidate variable and count for that one.
        2 - We can assume that the first element is the most frequent one, and keep iterating through the array
        3 - If the current element is different from the candidate, we just need to decrease the count by one
        4 - The correct candidate will remain at the end
    */
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate) count++;
            else count--;
            if (count <= 0) {
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }
};