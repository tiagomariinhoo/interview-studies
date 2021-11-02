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

int t, d, m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t >> d >> m;

  if(d < t) {
    cout << "N" << endl;
    return 0;
  }
  vector<int> vec;

  for(int i=0;i<m;i++) {
    int a;
    cin >> a;
    vec.push_back(a);
  }

  sort(vec.begin(), vec.end());
  vec.push_back(d);
  bool at = false;
  int sum = 0;
  int last = 0;


  for(int i=0;i<sz(vec);i++) {
    if(!at) {
      if(vec[i] - last >= t) at = true;
    } else {

    }
    last = vec[i];
  }

  if(!at) {
    cout << "N" << endl;
  } else {
    cout << "Y" << endl;
  }

  return 0;
}