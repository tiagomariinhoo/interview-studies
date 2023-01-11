#include <bits/stdc++.h>
using namespace std;


/**
 * Solution runs in n log n
*/
class Solution {
public:
    // Basically u can get the best answer using the memo table, and when u're doing
    // a binary search, u'll get the answer from the memo and not from the array directly
    
    struct Job {
      int start, finish, profit;  
    };
    vector<Job> vec;
    int memo[1010111];
    
    static bool comp(Job a, Job b) {
        return a.finish < b.finish;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        for(int i = 0; i < startTime.size(); i++) {
            Job job;
            job.start = startTime[i];
            job.finish = endTime[i];
            job.profit = profit[i];
            
            vec.push_back(job);
        }
        
        // N Log N
        sort(vec.begin(), vec.end(), comp);
        
        memo[0] = vec[0].profit;
        
        for(int i = 1; i < vec.size(); i++) {
            
            int current = vec[i].profit;
            //We need to check the index where vec[idx].finish <= vec[i].start
            //that's the reason that we need to sort by job.finish
            // for(int j = i - 1; j >= 0; j--)... n²
            
            /**
            When we're using a binary search, we can pick lower bound -> mid = (l + (r - l) / 2), avoid l = mid; (infinite loop)
            When we're using a binary search, we can pick upper bound -> mid = (r - (r - l) / 2), avoid r = mid; (infinite loop)
            
            The good point using this kind of mid = ..., is that we can avoid out bound index problem
            
            This case, we need to pick the upper bound index, since we want the rightmost job schedule
            */
            int l = 0, r = i - 1;
            while(l < r) {
                int mid = (r - (r - l) / 2);
                if(vec[mid].finish <= vec[i].start) l = mid;
                else r = mid - 1;
            }
            
            if(vec[l].finish <= vec[i].start) {
                // I have the best answer until here and this includes all previous job schedules and vec[l].profit
                current += memo[l];
            }
            
            memo[i] = max(memo[i - 1], current);
        }
        
        return memo[vec.size() - 1];
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}