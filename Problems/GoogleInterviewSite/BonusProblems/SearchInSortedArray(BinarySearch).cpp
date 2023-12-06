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
 * https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
 * 
 * Isn't so easy to think the solution and implement it, but it's
 * a good medium/hard problem.
 * 
 * Basically u have some options:
 * [1, 2, 3, 4, 5] // normal sorted array
 * [5, 1, 2, 3, 4] // Rotated array
 * [2, 3, 4, 5, 1] // another rotated array
 * 
 * For this solution, u need to check if the mid pos is == target
 * else:
 * U need to check if ur right is on the left partition or the rigth
 * partition
 * If nums[l] <= nums[mid], this means that u have a sorted array
 * into the left partition
 * else
 * if target > nums[mid] && target <= nums[r], means that is on the second partition
 * else
 * is on the first partition
 * 
 * The solution runs in log N complexity time
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while(l < r) {
            int mid = (l + (r - l) / 2);
            
            if(nums[l] <= nums[mid]) { // first partition
                if(nums[l] <= target && target <= nums[mid]) r = mid;
                else l = mid + 1;
            } else { // l > nums[mid]
                if(nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid;
            }
        }
        
        if(nums[r] == target) return r;
        
        return -1;
    }
};

/*
This other solution runs in the same complexity time but here
we first find the index where the array starts (the smallest number)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Find the idx where's rotated
        
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + (r - l) / 2); // avoid l = m
            
            if(nums[mid] >= nums[0] && nums[mid] >= nums[nums.size() - 1]) l = mid + 1;
            else if(nums[mid] <= nums[0] && nums[mid] <= nums[nums.size() - 1] || nums[0] < nums[nums.size() - 1]) r = mid;
        }
        
        int cut = r;
        
        if(target >= nums[cut] && target <= nums[nums.size() - 1]) {
            int l = cut, r = nums.size() - 1;
            while(l < r) {
                int mid = (l + (r - l) / 2);
                if(nums[mid] < target) l = mid + 1;
                else r = mid;
            }
            if(nums[r] == target)
                return r;
        } else {
            int l = 0, r = cut - 1;
            r = max(r, 0);
            
            while(l < r) {
                int mid = (l + (r - l) / 2);
                if(nums[mid] < target) l = mid + 1;
                else r = mid;
            }
            if(nums[r] == target)
                return r;
        }
        
        
        return -1;
    }
};

class Solution {
public:
    /**
        Solution runs in log N and takes constant auxiliary space

        It's important to notice that we have two cases:
        [5, 1, 3]
        When nums[mid] is < nums[l] at the beginning
        [4, 5, 6, 7, 0, 1, 2]
        When nums[mid]is >= nums[l] at the beginning

        - When nums[mid] >= nums[l], if my target is <= nums[mid] and target >= nums[l]
        it means that my target is between (l, mid), then r = mid
        otherwise, r = mid because it's on the other side

        - if nums[mid] < nums[l] at the beinning (like [5, 1, 3])
        then if target > nums[mid] and target <= nums[r], target is here (l, r), l = mid + 1
        else r = mid
    */

    int search(vector<int>& nums, int target) {
        int ans = 0;
        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2; // Avoid l = mid;
            cout << l << " - " << mid << " - " << r << endl;

            if (nums[mid] >= nums[l]) {
                if (target <= nums[mid] && target >= nums[l]) r = mid;
                else l = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid;
            }

            cout << l << " - " << mid << " - " << r << endl;
            
        }

        if (nums[r] == target) return r;

        return -1;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}