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
 * https://leetcode.com/contest/weekly-contest-312/problems/find-all-good-indices/
 * 
 * Solution: 
 * https://leetcode.com/problems/number-of-good-paths/discuss/2621772/C%2B%2B-or-Java-or-Diagram-or-Union-Find
 * https://codeforces.com/blog/entry/104678
 * 
 * 
 * It's a hard problem
 * 
 * First, one important thing is build a new graph where
 * value[node[a]] >= value[node[b]] and make node[a] -> node[b]
 * 
 * After that, just loop through 
 * 
 * The solution runs in O (dsu(n))
 */

class Solution {
public:
    int parent[100001];
    int rank[100001];
    vector<int> adj[100001];
    map<int, vector<int>> valueNodes;
    
    int find(int x) {
        if(parent[x] == x) return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void join(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(rank[x] < rank[y]) {
            parent[x] = y;
        } else if(rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        for(int i = 0; i < vals.size(); i++) parent[i] = i;
        
        for(int i = 0; i < vals.size(); i++) {
            valueNodes[vals[i]].push_back(i);
        }
        
        for(auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            
            if(vals[a] >= vals[b]) {
                adj[a].push_back(b);
            } else {
                adj[b].push_back(a);
            }
        }
        
        int ans = 0;
        // starting from nodes with small value, since it's a map
        for(auto i : valueNodes) {
            int value = i.first;
            // conect the adj nodes
            for(auto node : i.second) {
                for(auto neighbor : adj[node]) {
                    join(node, neighbor);
                }
            }
            
            // Check how many groups
            // and how many nodes with current value in each group
            unordered_map<int, int> groupSize;

            for(auto node : i.second) {
                groupSize[find(node)]++;
            }
            
            ans += i.second.size();
            
            for(auto j : groupSize) {
                if(j.second > 1) {
                    ans += (j.second * (j.second - 1)) / 2;
                }
            }
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}