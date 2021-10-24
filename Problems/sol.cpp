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

int t;

int n;
int ancestral[MAXN][MAXL];
int pai[MAXN];
int nivel[MAXN];
lli dist[MAXN];
vector<ii> vec[MAXN];
int vis[MAXN];
lli answer[MAXN];

void dfs(int x, int p){
    for(auto i : vec[x]){
        int u = i.F, d = i.S;
        if(u == p) continue;
        nivel[u] = nivel[x] + 1;
        pai[u] = x;
        dist[u] = dist[x] + d;
        dfs(u, x);
    }
}

void build(){
    memset(ancestral, -1, sizeof ancestral);
    dfs(1, 1);

    for(int i=1;i<=n;i++) ancestral[i][0] = pai[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<MAXL;j++){
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
        }
    }
}

int LCA(int u, int v){
    if(nivel[u] < nivel[v]) swap(u , v);
    for(int i = MAXL-1;i>=0;i--){
        if(nivel[u] - (1 << i) >= nivel[v]){
            u = ancestral[u][i];
        }
    }

    if(u == v) return u;

    for(int i=MAXL-1;i>=0;i--){
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }
    return pai[u];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

    int q;
    cin >> n >> q;
    memset(pai, 0, sizeof pai);
    memset(nivel, 0, sizeof nivel);
    memset(dist, 0, sizeof dist);

    for(int i=0;i<MAXN;i++) vec[i].clear();
    for(int i=0;i<n-1;i++) {
      int a, b, c;
      cin >> a >> b >> c;
      vec[a].push_back({b, c});
      vec[b].push_back({a, c});
    }

    build();

    for(int i=1;i<=n;i++) {
      for(int j=1;j<=n;j++) {
        if(i == j) continue;
        answer[i] = max(answer[i], min(answer[j], dist[i] + dist[j] - 2*dist[LCA(i, j)]));
      }
    }
    
    for(int i=0;i<q;i++) {
      int a, b;
      cin >> a >> b;
      cout << answer[b] << endl;
    }


  return 0;
}