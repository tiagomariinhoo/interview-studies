#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(1e5 + 5)
#define MAXL 20
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 9)
#define MOD2 (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, lli> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

/**
 * https://leetcode.com/contest/weekly-contest-310/problems/divide-intervals-into-minimum-number-of-groups/
 * 
 * Not a very easy idea, but you just need to take each interval
 * and mark as 1 the beginning and -1 the last index + 1 (to include the
 * last index). Basically u just need to keep looping through the array
 * and u will get the position with more intersections
 * For example:
 * 
 * [[5,10],[6,8],[1,5],[2,3],[1,10]]
 * 
 * The array would be:
 * 2 1 0 -1 1 0 0 0 -1 0 -2
 * 
 * Then looping through the array
 * at the index 3, we should have a sum = 3,
 * then that's should be the max number of intersections
 * and consequently, the answer.
 * 
 * This works because we can store all the
 * start and end intervals and we can keep updating
 * the sum all the time to check the maximum sum
 * while we are looping through
 * 
 * That's works in linear time
 * With linear auxiliary space
 * 
 */

class Solution {
public:
    
    int sum[1000011];
    
    int minGroups(vector<vector<int>>& intervals) {
        
        for(auto i : intervals) {
            sum[i[0]]++;
            sum[i[1] + 1]--;
        }
        
        int ans = 0;
        int aux = 0;
        for(int i = 0; i <= 1000000; i++) {
            aux += sum[i];
            ans = max(ans, aux);
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}