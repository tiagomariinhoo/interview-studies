#include <bits/stdc++.h>

using namespace std;

/**
 * The problem is just given an array
 * where u can apply queries for Add Numbers
 * or Find Median.
 * 
 * The problem can be solved using two Priority Queues.
 * The Time Complexity is Log N and the Space is Linear
 * 
 * The First priority queue will store the MaxValue
 * from the left side (storing the minimal values)
 * 
 * The second priority queue will store the MinValue
 * from the right side (storing the maximal values)
 * 
 * When u add a new value, I will just check if
 * I can put the new value on my second Priority queue
 * This will guarantee that the both of them will
 * always rebalance the values. For example, I will have:
 * 
 * 1 2 3 4 5, and my Pq will be:
 * Pq1 : 1 2 3
 * Pq2 : 4 5
 */

class MedianFinder {
public:
    priority_queue<double> maxPq;
    priority_queue<double, vector<double>, greater<double> > minPq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxPq.push(num);
        minPq.push(maxPq.top());
        maxPq.pop();
        
        if(minPq.size() > maxPq.size()) {
            maxPq.push(minPq.top());
            minPq.pop();
        }
        
    }
    
    double findMedian() {
        if(maxPq.size() == minPq.size()) {
            return ((maxPq.top() + minPq.top()) / 2);
        }
        
        return maxPq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {

  return 0;
}