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
 * https://leetcode.com/contest/weekly-contest-308/problems/minimum-amount-of-time-to-collect-garbage/
 * 
 * Just implementation, linear time
 * 
 * Store the distances and use them if there's a garbage in the current slot
 */

class Solution {
public:
    
    int vec[100001][3];
    vector<int> globalTravel;
    vector<string> globalGarbage;
    
    int getGarbage(int current) {
        int sum = 0;
        int distance = 0;
        for(int i = 0; i < globalGarbage.size(); i++) {
            if(i > 0) distance += globalTravel[i - 1];
            if(vec[i][current] > 0) {
                sum += distance + vec[i][current];
                distance = 0;
            }
        }    
        
        return sum;
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        globalTravel = travel;
        globalGarbage = garbage;
        
        for(int i = 0; i < garbage.size(); i++) {
            for(int j = 0; j < garbage[i].size(); j++) {
                if(garbage[i][j] == 'M') {
                    vec[i][0]++;
                } else if(garbage[i][j] == 'P') {
                    vec[i][1]++;
                } else {
                    vec[i][2]++;
                }
            }
        }
        
        ans += getGarbage(0);
        ans += getGarbage(1);
        ans += getGarbage(2);
        
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}