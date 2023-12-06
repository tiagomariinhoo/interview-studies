class Solution {
public:
    /**
     * https://leetcode.com/problems/find-k-closest-elements/description/
     * 
        It was a very interesting problem because it was my first time using multiset in C++
        As a Set
        Insertion, lookup and deletion takes O(log N)

        Here we are using a multiset just to simulate a double-ended priority-queue, since we need to remove the
        first or the last element (that they will be always the furthest element from X). Set doesn't work here 
        because using a Set, you cannot store the same element multiple times.

        The solution takes O (N * log N)
    */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multiset<int> aux;
        vector<int> ans;

        for (auto i : arr) {
            if (aux.size() < k) {
                aux.insert(i);
            } else {
                int dif = abs(*aux.begin() - x);
                int dif2 = abs(*aux.rbegin() - x);
                
                int current = abs(x - i);

                if (dif >= dif2 && dif > current) {
                    aux.erase(aux.begin());
                    aux.insert(i);
                } else if (dif2 >= dif && dif2 > current) {
                    aux.erase(prev(aux.end()));
                    aux.insert(i);
                }
            }
        }

        for (auto i : aux) ans.push_back(i);

        return ans;
    }
};