#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/minimum-height-trees/solution/
 * 
 * solution using topological sort, first u need to take all nodes that are leafs and the solution is O(V)
 * 
 * We can use topological sort to take the centroid but just taking care with the corner case of
 * to have 2 centroids
 */ 

class Solution {
public:
    vector<int> vec[30101];
    int maxi = -1;
    int maxi2 = -1;
    int vis[30101];
    int subtree[30101];
    int degree[30101];
    int lastNode = 0;
    vector<int> ans;
    
    void solve(int node, int dist, bool at) {
        if(vis[node]) return ;
        vis[node] = 1;
        
        if(!at) {
            maxi = max(maxi, dist);
        } else {
            maxi2 = max(maxi2, dist);
        }
        
        for(auto i : vec[node]) {
            solve(i, dist + 1, at);
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) {
            ans.push_back(0);
            return ans;
        }
        
        if(edges.size() == 1) {
            ans.push_back(edges[0][0]);
            ans.push_back(edges[0][1]);
            return ans;
        }
        
        for(auto i : edges) {
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }
        
        queue<int> q;
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(vec[i].size() == 1) {
                vis[i] = 1;
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            st.push(current);
            
            for(auto i : vec[current]) {
                degree[i]--;
                if(degree[i] <= 1 && !vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
                subtree[i] = max(subtree[i], subtree[current] + 1);
            }
        }
        
        // for(int i = 0; i < n; i++) cout << i << " - " << subtree[i] << endl;
        
        int mid = st.top();
        st.pop();
        memset(vis, 0, sizeof vis);
        solve(mid, 0, false);
        ans.push_back(mid);
        
        if(st.size() > 0) {
            memset(vis, 0, sizeof vis);
            mid = st.top();
            st.pop();
            solve(mid, 0, true);   
            if(maxi == maxi2) ans.push_back(mid);
        }
        
        return ans;
    }
};

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  maxArea()
  
  return 0;
}