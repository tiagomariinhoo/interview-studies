class Solution {
public:

    int memo[13][10011];

    /**
        Classical dynamic programming problem.

        Usually for this kind of problem, the best approach to solve it, is just build the function
        that solve it in backtracking complexity time, without the dynamic programming
        The naive solution takes coins.len ^ amount
        We can reduce it to
        coins.len * amount, complexity time
        By using Dynamic Programming, storing the current coin and amount

        Also, another detail is that we want to minimize the number of coins, so we can use the greedy idea
        of sort the coins and always starts from the most valuable coin
    */

    int solve(int idx, int amount, vector<int> &coins) {
        if (amount < 0) return 1e9;
        if (idx < 0 and amount == 0) return 0;
        else if (idx < 0) return 1e9;

        if (memo[idx][amount] != -1) return memo[idx][amount];

        int sum = 0;
        int a = solve(idx - 1, amount, coins);
        for (int i = (amount / coins[idx]); i >= 0; i--) {
            a = min(a, solve(idx - 1, amount - (i * coins[idx]), coins) + i);
        }

        return memo[idx][amount] = a;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        memset(memo, -1, sizeof memo);
        int ans = solve(coins.size() - 1, amount, coins);

        if (ans >= 1e9) return -1;
        return ans;
    }
};