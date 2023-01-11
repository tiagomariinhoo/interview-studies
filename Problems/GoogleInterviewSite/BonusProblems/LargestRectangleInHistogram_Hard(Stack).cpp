#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Linear solution using Stack
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int> > st;
        int ans = 0;
        
        /**
         * It's important to notice that:
         * U need keep looping through the array and
         * when u find a height[i] <= stack.top()
         * u just need keep removing the top until
         * u find a element < height[i], since we're cutting off
         * all the taller heights since we can't use them in our area
         * 
         * In parallel u need to keep checking if u found a better answer
         * 
         * After that, the stack will contains just heights in a increasing
         * order. Then, u just need to use them calculating the width
         * from the end until the current index
        */
        for(int i = 0; i < heights.size(); i++) {
            int idx = i, h = heights[i];
            while(!st.empty() && st.top().second >= h) {
                auto aux = st.top();
                idx = aux.first;
                st.pop();
                ans = max(ans, (i - idx) * aux.second);
            }
            
            
            st.push({idx, h});
        }
        
        while(!st.empty()) {
            auto aux = st.top();
            st.pop();
            int current = aux.second * (heights.size() - aux.first);
            if(current > ans) ans = current;
        }
        
        return ans;
    }
};

/**
 * N Log N solution beautiful but less efficient
 * using divide and conquer
*/
class Solution {
public:
    vector<int> vec;
    
    int getMaxArea(int l, int r) {
        if(r < l) return -1;
        if(r == l) return vec[l];
        
        int idx = l;
        for(int i = l; i <= r; i++) {
            if(vec[i] < vec[idx]) {
                idx = i;
            }
        }
        
        return max(
            {
                getMaxArea(l, idx - 1),
                getMaxArea(idx + 1, r),
                (r - l + 1) * vec[idx]
            }    
        );
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vec = heights;
        return getMaxArea(0, vec.size() - 1);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}