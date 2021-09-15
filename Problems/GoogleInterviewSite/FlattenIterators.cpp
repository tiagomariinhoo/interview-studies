#include <bits/stdc++.h>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * 
 * https://techdevguide.withgoogle.com/resources/former-interview-question-flatten-iterators/#!
 * https://www.youtube.com/watch?v=UO8ZbLhnoPk solution
 * https://leetcode.com/problems/flatten-nested-list-iterator/submissions/ Problem at leetcode
 * 
 */

class NestedIterator {
    vector<int> answer;
    int i = 0;
public:
    
    void helper(vector<NestedInteger> &nestedList) {
        for(auto j : nestedList) {
            if(j.isInteger()) {
                answer.push_back(j.getInteger());
            } else {
                helper(j.getList());
            }
        }   
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        int ans = answer[i];
        i++;
        
        return ans;
    }
    
    bool hasNext() {
        if(i < answer.size()) return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main () {

  return 0;
}