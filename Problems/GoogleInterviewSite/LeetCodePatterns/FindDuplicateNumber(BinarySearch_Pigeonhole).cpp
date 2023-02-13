class Solution {
public:

    /**
        Linear solution with constant time space

        That's a really interesting problem and we can use binary search using pigeonhole principle
        If N items are put into M container, with N > M, at least one container must contain one more item

        So here, we can use binary search to check for our current numebr, if there's count < mid;
        For example, let's suppose that we have
        1, 3, 4, 2, 2
        Since we guarantee that we have one repeated number, so will have from 1 to n - 1 numbers.
        So here, we have l = 0 and r = n - 1,
        mid = 2
        We will iterate into the array to check how many numbers are less or equal than our current mid. For this case
        3 numbers are less or equal than 2, so, there's something wrong becuase in an usual case, we should have just
        [1, 2], 2 numbers less or equal, so we can do r = mid to try with a smaller number.
        The mid now will be one and the number of less or equal numbers will be 1, that's correct, so l = mid + 1
        and we go back to 2 and we will find the answer.
    */

    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1; // -1 cuz is guaranteed that there's one repeated number

        while (l < r) {
            int mid = l + (r - l) / 2; // l + (r - l) / 2, avoid l = m, r - (r - l), avoid r = m [infinite loop]
            int c = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] <= mid) c++;
            }

            if (c <= mid) l = mid + 1;
            else r = mid;
        }

        return l;
    }
};