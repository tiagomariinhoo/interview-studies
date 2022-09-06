#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
 * 
 * That's the kind of problem that u will do a binary search in the answer
 * The range for the binary search is the first value m[0][0] and last value m[n-1][n-1]
 * 
 * For each attempt, m = l + (r - l) / 2 to avoid overflow and do a lower bound
 * and for each step, will count how many numbers are less than the current number 'm'
 * 
 * For rows just need to compare the last cell of the row, when u reach a row that the
 * last cell is >= current number, just check that row to see how many numbers are less than
 * the current
 * 
 * Doing it, u ensure that the current number can be the answer, at the end
 * if the number of numbers < k, l = m + 1 (cause u want to include m + 1, since < k)
 * or r = m
 * 
 * One important thing is that u need to check ALL ROWS, since u can get some numbers in each row
 * For example:
 * 1 2
 * 1 3, k == 2
 * The answer is 1
 * but u don't wanna to stop in the first row since m[0][n-1] > 1, 
 * U want to get the number 1 in the second row as well
 * 
 * This takes n log n complexity time
 */ 

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        
        while(l < r) {
            int m = l  + (r - l) / 2;
            int count = 0;
            
            for(int i = 0; i < n; i++) {
                if(matrix[i][n - 1] < m) count += n;
                else {
                    for(int j = n - 1; j >= 0; j--) {
                        if(matrix[i][j] <= m) {
                            count += j+1;
                            break;
                        }
                    }
                }
            }
            
            if(count < k) l = m + 1;
            else r = m;
        }
        
        return l;
    }
};

int main() {

  return 0;
}