#include <bits/stdc++.h>

using namespace std;

/**
 * https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 * 
 * Testing lower and upper bound: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
 * 
 * Article about binary search and implementations
 * 
 * Some points to bring it out
 * 
 * When we choose use: m = l + (r - l) / 2, we want to make sure to avoid l = mid
 * When we choose use: m = r - (r - l) / 2, we want to make sure to avoid r = mid
 * 
 * So, shall we assign values 
 * l = mid + 1
 * r = mid
 * 
 * or 
 * 
 * l = mid
 * r = mid - 1
 */ 

/*
Basically using l + (r - l) / 2, avoid use l = m, use it when lower bound
. . . . 5 6 7 8 . . . .
          ^
Using r - (r - l) / 2, avoid use r = m, use it when upper bound
. . . . 5 6 7 8 . . . .
            ^
*/
int lowerBound(vector<int> vec, int target) {
  int l = 0, r = vec.size() - 1;
  while(l < r) {
    int m = l + (r - l) / 2; // To avoid overflow
    if(vec[m] < target) l = m + 1;
    else r = m;
  }

  // cout << l << " - " << r << endl;

  return vec[l] == target ? l : -1;
}

int upperBound(vector<int> vec, int target) {
  int l = 0, r = vec.size() - 1;
  /**
   * Here we want to make sure that we don't want to use l + (r - l) / 2 with l = m
   * to avoid infinite loop
   */ 
  while(l < r) {
    int m = r - (r - l) / 2;
    if(vec[m] > target) r = m - 1;
    else l = m;
  }

  cout << l << " " << r << endl;

  return vec[l] == target ? l : -1;
}

vector<int> searchRange(vector<int> nums, int target) {
  vector<int> ans;

  ans.push_back(lowerBound(nums, target));
  ans.push_back(upperBound(nums, target));

  return ans;
}

int main () {

  vector<int> aux = {5,7,7,8,8,8,8,8,8,10};
  // vector<int> aux = {5};
  int target = 7;
  searchRange(aux, target);

  return 0;
}