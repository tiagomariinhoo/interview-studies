#include <bits/stdc++.h>

using namespace std;

vector<int> vec = {0,1,3,2,4,1,3,1,4,5,2,2,1,4,2,2};
int n;
int tree[4*100101];

void build(int node = 1, int start = 1, int end = n) {
  if(start == end) {
    tree[node] = vec[start];
  } else {
    int mid = (start + end) >> 1;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);
    tree[node] = max(tree[2*node], tree[2*node+1]);
  }
}

int query(int l, int r, int node = 1, int start = 1, int end = n) {
  if(r < start or end < l) return -1;
  if(start >= l and end <= r) return tree[node];

  int mid = (start + end) >> 1;
  int q1 = query(l, r, 2*node, start, mid);
  int q2 = query(l, r, 2*node+1, mid + 1, end);

  return max(q1, q2);
}

int main() {
  // N * log N using Segment Tree
  /**
   * https://techdevguide.withgoogle.com/resources/former-interview-question-volume-of-lakes/#!
   * 
   * Given an array of positive integers representing 
   * 2-D bar heights, design an algorithm 
   * (or write a function) that can compute the total
   * volume (capacity) of water that could be
   * held in all lakes on such an island given
   * an array of the heights of the bars. Assume
   * an elevation map where the width of each bar is 1.
   * 
   * Solution:
   * Using seg tree to get the max value 
   * in the left and right ranges
   */

  n = vec.size();
  build();

  int ans = 0;
  for(int i=2;i<vec.size()-1;i++) {
    int value = max(min(query(1, i - 1), query(i + 1, vec.size())) - vec[i], 0);
    ans += value;
  }

  cout << ans << endl;


  return 0;
}