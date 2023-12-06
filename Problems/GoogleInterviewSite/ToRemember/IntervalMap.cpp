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

template<typename K, typename V>

class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
    if (!(keyBegin < keyEnd))  return ;

		// Just to fill the map with the initial value before make the operation
		if (m_map.empty()) m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), m_valBegin));;

		// cout << "Keys: " << keyBegin << " - " << keyEnd << endl;
		// cout << val << endl;
		// cout << this->operator[](keyBegin) << " - " << this->operator[](keyEnd) << endl;

    K leftKey = keyBegin;
    auto leftIdx = m_map.lower_bound(keyBegin);
    auto rightIdx = m_map.lower_bound(keyEnd);
		// I used it to keep the correct value in [keyEnd, ...]
    auto currentValue = this->operator[](keyEnd);
    
		cout << "Current Value : " << currentValue << endl;
    if (!(currentValue == val)) {
      m_map[keyEnd] = currentValue;
      rightIdx = m_map.find(keyEnd);
    }


		// Check if there's a leftIdx where the value is the same
    if (leftIdx != m_map.begin() and std::prev(leftIdx)->second == val) {
      leftIdx = std::prev(leftIdx);
      leftKey = leftIdx->first;
    }

		// Erase just to solve the canonical case
    if (leftIdx != m_map.end()) {
      m_map.erase(leftIdx, rightIdx);
    }
    
    m_map[leftKey] = val;
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

	void print() {
		for (auto &&[key, val] : m_map) {
			std::cout << "[" << key << ':' << val << "]";
		} cout << endl;
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main () {
  interval_map<int, char> map{'a'};
	map.print(); // [-2147483648:a]

	map.assign(3, 5, 'b');
	map.print(); // [-2147483648:a][3:b][5:a]

	map.assign(2, 3, 'c');
	map.print(); // [-2147483648:a][2:c][3:b][5:a]

	map.assign(2, 3, 'd');
	map.print(); // [-2147483648:a][2:d][3:b][5:a]

	map.assign(2, 4, 'e');
	map.print(); // [-2147483648:a][2:e][4:b][5:a]

	map.assign(4, 18, 'f');
	map.print(); // [-2147483648:a][2:e][4:f][18:a]

	map.assign(2, 8, 'g');
	map.print(); // [-2147483648:a][2:g][8:f][18:a]

	map.assign(0, 10, 'a');
	map.print(); // [-2147483648:a][10:f][18:a]

	map.assign(0, 20, 'a');
	map.print(); // [-2147483648:a]

	map.assign(0, 30, 'a');
	map.print(); // [-2147483648:a]
	

  return 0;
}