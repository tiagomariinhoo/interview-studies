#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(3*1e5 + 5)
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

int q;
vector<int> vec[MAXN];
int last = 2;
int t = 1;
int vis[MAXN];
int vis2[MAXN];
int tempo[MAXN];
vector<pair<int, int> > morte;
queue<int> myq;

void solve(int x) {
  myq.push(x);
  for(auto i : vec[x]) {
    solve(i);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> q;
  while(q--) {
    int a, b;
    cin >> a >> b;

    if(a == 1) {
      vec[b].push_back(last++);
      tempo[b] = (t++);
    } else {
      morte.push_back({b, t++});
    }
  }
  solve(1);

  int ans = 1;

  for(auto i : morte) {
    vis2[i.F] = 1;
    if(i.F != ans) {
      cout << ans << endl;
    } else {
      while(!myq.empty()) {
        int u = myq.front();
        myq.pop();
        if(vis2[u]) continue;
        ans = u;
        break;
      }
      cout << ans << endl;
    }
  }

  return 0;
}