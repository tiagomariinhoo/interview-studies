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
 * https://leetcode.com/contest/weekly-contest-307/problems/minimum-hours-of-training-to-win-a-competition/
 * 
 * Just an adhoc problem, linear time
 */

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        
        int ene = initialEnergy;
        int exp = initialExperience;
        
        for(int i = 0; i < energy.size(); i++) {
            if(energy[i] >= ene) {
                ans += (energy[i] - ene + 1);
                ene = 1;
            } else {
                ene -= energy[i];
            }
            
            if(experience[i] >= exp) {
                ans += (experience[i] - exp + 1);
                exp = experience[i] + 1;
                exp += (experience[i]);
            } else exp += experience[i];
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}