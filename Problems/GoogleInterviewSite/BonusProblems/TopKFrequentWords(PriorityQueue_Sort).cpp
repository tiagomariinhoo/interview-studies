#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/top-k-frequent-words/
 * 
 * Just be careful when use operator overload for priority queue
 * 
 * The return a.first < b.first will do:
 * 
 * 1 <- 2 <- 3 (top element)
 * 
 * And when u do pq.top(), u will get the element 3
 * 
 * Using it into the sort functions, u will see that
 * the first element will be 1
 */ 

class Solution {
public:
    
    static bool comp(pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first) return a.second < b.second;
        
        return a.first > b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> stringMap;
        
        for(auto i : words) {
            stringMap[i]++;
        }
        
        vector<pair<int, string>> vec;
        
        for(auto i  : stringMap) {
            vec.push_back({i.second, i.first});
        }
        
        sort(vec.begin(), vec.end(), comp);
        
        
        vector<string> ans;
        int j = 0;
        for(auto i : vec) {
            ans.push_back(i.second);
            j++;
            if(j == k) break;
        }
        
        for(auto i : ans) cout << i << endl;
        
        return ans;
    }
};

//Pq comp solution

class Solution {
public:
    
    struct cmp {
        bool operator()(pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }

            return a.first > b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> stringCount;
        
        for(auto word: words) {
            stringCount[word]++;
        }
        
        priority_queue< pair<int, string>, vector< pair<int, string> >, cmp> pq;
        
        for(auto i : stringCount) {
            if(pq.size() < k) {
                pq.push({i.second, i.first});
            } else {
                if(pq.top().first < i.second) {
                    pq.pop();
                    pq.push({i.second, i.first});
                } else if(pq.top().first == i.second) {
                    if(pq.top().second > i.first) {
                        pq.pop();
                        pq.push({i.second, i.first});
                    }
                }
            }
        }

        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        
        return ans;
    }
};

//another pq solution
class Solution {
public:
    
    struct cmp {
        bool operator()(pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }

            return a.first < b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> stringCount;
        
        for(auto word: words) {
            stringCount[word]++;
        }
        
        priority_queue< pair<int, string>, vector< pair<int, string> >, cmp> pq;
        
        for(auto i : stringCount) {
            pq.push({i.second, i.first});
        }

        vector<string> ans;
        
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}