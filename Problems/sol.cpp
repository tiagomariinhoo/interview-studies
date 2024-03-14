#include <bits/stdc++.h>
using namespace std;

/**
  My solution that takes N log N using Seg Tree

  1 - First build the seg tree starting the tree with zeroes
  2 - The trick here is to use the segtree to get the range sum
  3 - Another trick is to update the segment with one's

  To update the range we need to do:
  tree[node] |= val; 
  So we can make sure that we won't sum the same cell twice
*/

int tree[100000];
int n = 100000;

void build (int node = 1, int start= 1, int end = n) {
  if (start == end) {
    tree[node] = 0;
  }
  int mid = (start + end) / 2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node] = tree[2*node] + tree[2*node+1];
}

int query (int l, int r, int node = 1, int start = 1, int end = n) {
  if (l > end || r < start) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  int q1 = query(l, r, 2 * node, start, mid);
  int q2 = query(l, r, 2 * node + 1, mid + 1, end);
  return q1 + q2;
}

void updateRange(int l, int r, int val, int node = 1, int start = 1, int end = n) {
  if (start > end || start > r || end < l) return ;
  if (start == end) {
    tree[node] |= val;
    return ;
  } 
  int mid = (start + end) / 2;
  updateRange(l, r, val, 2*node, start, mid);
  updateRange(l, r, val, 2*node + 1, mid + 1, end);
  tree[node] = tree[2*node] + tree[2 * node + 1];
}

int main () {
  // build();
  updateRange(1, 3, 1);
  cout << query(1, 3) << endl;
  

  return 0;
}