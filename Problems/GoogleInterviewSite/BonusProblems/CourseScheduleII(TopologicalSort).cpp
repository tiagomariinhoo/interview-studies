#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/course-schedule-ii/submissions/
 * 
 * Just run a normal topological sort
 */ 

class Solution {
public:
    vector<int> vec[2001];
    vector<int> ans;
    int prereq[2001];
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i : prerequisites) {
            vec[i[1]].push_back(i[0]);
            prereq[i[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(!prereq[i]) {
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto i : vec[node]) {
                prereq[i]--;
                if(!prereq[i]) {
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        
        if(ans.size() < numCourses) {
            return vector<int> ();
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}