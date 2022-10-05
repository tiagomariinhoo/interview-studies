#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/k-closest-points-to-origin/
 * 
 * Just calculate the distances in a normal way and sort the array
 * with the distances
 * 
 * Linear time
 */ 

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int> > ans;
        vector<pair<long double, pair<int, int> > > vec;
        // sqrt(x² + y²)
        for(auto i : points) {
            long double dist = sqrt((i[0]*i[0]) + (i[1]*i[1]));
            vec.push_back({dist, {i[0], i[1]}});
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < k; i++) ans.push_back({vec[i].second.first, vec[i].second.second});
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}