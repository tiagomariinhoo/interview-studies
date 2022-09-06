#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/burst-balloons/
 * 
 * Usually a normal way to solve dp problems like knap
 * is go through index by index choosing to get the index
 * or no:
 * knap(idx + 1)
 * knap(idx + 1) + val[idx]
 * 
 * The problem here is that u can start from index 2, for instance,
 * go to index 5 and go back to index 3 (there is no order)
 * 
 * You need burst ballons, where bursting a balloon is get the number of coins:
 * nums[i-1] * nums[i] * nums[i+1] and remove nums[i] from the list
 * You have to get the maximum number of coins after burst all balloons
 * 
 * The naive approach for this problem is recursively passing a vector by param
 * trying remove each element, passing a vector without the current element for the
 * next step
 * This will take n^n complexity time and a insane waste of memory
 * 
 * The best approach is starting from the end, assuming that u are with just the
 * last element and u'll put an element step by step
 * 
 * Let's suppose nums = [3, 1, 5, 8], n = 4
 * We start changing it to: nums = [1, 3, 1, 5, 8, 1]
 * But we'll work in range [1...4], since the leftmost and rightmost elements
 * don't belong to the original array, is just to simplify the things
 * 
 * Now, we can use a divide and conquer technique, assuming that we're removing an element, like:
 * - We start our code with: left = 1 and right = n
 * 
 * for(int i = left; i <= n; i++) {
 *    ans = max({
 *      ans,
 *      // i - 1 because we are removing index[i]
 *      solve(left, i - 1) +
 *      // i + 1 because we are removing index[i]
 *      solve(i + 1, right) +
 *      // The normal operation but left - 1 because should be the
 *      // leftmost element at the moment (this case would be 1 from index 0)
 *      // and right + 1 for the same logic
 *      nums[i] * nums[left - 1] * nums[right + 1]
 *    })
 * }
 * 
 * When I do: solve(left, i - 1) + solve(i + 1, right) we want to get the max ans
 * for each side and the good point for that is that the next iteration, for each one of them
 * my bound will be delimited by current index [i], then for example, assuming that I remove
 * index 3 and pass: solve(1, 2) + solve(4, 4), my next iteration will have:
 * **For the left side
 * I can now remove idx 1 or 2, and no matter which one I take, my leftmost will be 1 and
 * my rightmost now will be my nums[3] = 1
 * **For the right side
 * Will follow the same logic
 * 
 * Memory O(N²)
 * Complexity Time O(N³)
 */ 

class Solution {
public:
    
    int ans = 0;
    vector<int> vec;
    int memo[301][301];
    
    int solve(int a, int b) {
        if(a > b) return 0;
        if(memo[a][b] != -1) return memo[a][b];
        
        int ans = 0;
        for(int i = a; i <= b; i++) {
            ans = max(ans, solve(a, i - 1) + solve(i + 1, b) + (vec[i] * vec[a - 1] * vec[b + 1]));
        }
        
        return memo[a][b] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        vec.push_back(1);
        for(auto i : nums) vec.push_back(i);
        vec.push_back(1);
        
        memset(memo, -1, sizeof memo);
        
        return solve(1, nums.size());
    }
};

int main() {

  return 0;
}