#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/search-a-2d-matrix/
 * 
 * We can use the same idea https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
 * 
 * First we can do a binary search looking for the last element
 * for each row, when we find a row that the last element is < target
 * then means that the target will be there (in that row)
 * 
 * Then we need to do another binary search for that row and find the element
 * 
 * Always remember to use l + (r - l) / 2 and avoid l = mid;
 * 
 * Runs in Log(M + N)
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + (r - l) / 2); // avoid l = mid;
            if(matrix[mid][m - 1] < target) l = mid + 1;
            else r = mid;
        }
        
        int row = r;
        
        l = 0, r = m - 1;
        while(l < r) {
            int mid = (l  + (r - l) / 2); // avoid l = mid;
            
            if(matrix[row][mid] < target) l = mid + 1;
            else r = mid;
        }
        int col = r;
        
        return (matrix[row][col] == target);
    }
};

int main() {

  return 0;
}