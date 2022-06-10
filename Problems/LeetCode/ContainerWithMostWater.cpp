#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/container-with-most-water/
 * 
 * Two Pointers problem
 * 
 * Basically u just need to put a pointer at the beginning and at the end 
 * and compare which wall is smaller. This will guarantee that u'll keep
 * the biggest wall in the both sides
 */ 

int maxArea(vector<int>& height) {
  int l = 0, r = height.size() - 1;
  long long int ans = 0;
  
  while(l < r) {
    long long int aux = min(height[l], height[r]) * (r - l);
    if(aux > ans) ans = aux;

    if(height[l] < height[r]) {
      l++;
    } else r--;
  }

  return ans;
}

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  maxArea()
  
  return 0;
}