class Solution {
public:
    /**
        If we make num[i] = num[i] % value, (taking care about the negative numbers)
        we gonna put all the numbers for the initial value
        
        Initially, the goal is put all the numbers starting from zero
        After that, we have our ans = 0, because the answer starts from zero.
        
        We just need to keep trying to generate new answers, doing like:
        If we have the current number already, it's okay, we just need to try the next answer (ans + 1)
        If we don't have the current number, we need to check if we have a number that adding value on this number
        we can reach the current answer (by checking ans%value)
        
        The solution runs in linear time and takes linear auxiliary space too
    */
    int findSmallestInteger(vector<int>& nums, int value) {
        int ans = 0;
        for (auto &i : nums) {
            if (i > 0) {
                i %= value;
            } else {
                int current = i;
                current *= -1;
                int div = current / value;
                i += ((div) * value);
                if (i < 0) i += value;
            }
        } 
        unordered_map<int, int> qt;
        
        for (auto i : nums) {
            qt[i]++;
        }
        
        while(1) {
            if (qt[ans] >= 1) {
                ans++;
            } else {
                if (qt[ans%value] > 1) {
                    qt[ans%value]--;
                    qt[ans] = 1;
                    ans++;
                } else {
                    break;
                }
            }
        }
        
        
        return ans;
    }
};