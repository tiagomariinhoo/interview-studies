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
 * https://leetcode.com/problems/course-schedule/submissions/
 * 
 * The solution runs in O (V + E)
 * 
 * And basically use the approach to store the visited time
 * 
 * If im making a dfs, Im filling all nodes with vis = 1
 * When I leave this Node, I will fill with vis = 2, this means that
 * he belongs to other dfs
 * 
 * If in some case I found some node with vis == 1, this means that
 * I found a cycle
 */ 

class Solution {
public:
    vector<int> adjList[100001];
    bool at = true;
    int vis[100001];
    
    void dfs(int x) {
        vis[x] = 1;
        for(auto i : adjList[x]) {
            if(vis[i] == 1) {
                at = false;
                continue;
            } else if(vis[i] == 2) {
                continue;
            }
            
            dfs(i);
        }
        
        vis[x] = 2;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(auto i : prerequisites) {
            adjList[i[1]].push_back(i[0]);
        }
        
        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        
        return at;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}