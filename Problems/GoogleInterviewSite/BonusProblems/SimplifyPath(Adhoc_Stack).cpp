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
 * https://leetcode.com/problems/simplify-path/submissions/
 * 
 * Adhock implementation with stack
 * Linear time
 */

class Solution {
public:
    vector<string> separateWords(string path) {
        vector<string> words;
        string aux = "";
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/') {
                if(aux.size() > 0)
                    words.push_back(aux);
                words.push_back("/");
                aux = "";
            } else {
                aux += path[i]; 
            }
        }
        if(aux.size() > 0) {         
            words.push_back(aux);   
        }
        
        return words;
    }
    
    string simplifyPath(string path) {
        stack<string> st;
        vector<string> words = separateWords(path);
        string ans = "";
        
        for(auto i : words) cout << i << " ";
        cout << endl;
        
        for(int i = 0; i < words.size() ; i++) {
            if(words[i] == ".") {
                if(st.size() > 1)
                    st.pop();
                continue;
            }
            if(words[i] == "..") {
                if(st.size() > 1) {
                    st.pop();
                    string current = st.top();
                    if(current.size() == 1 && current[0] == '.' || current.size() == 2 && current[1] != '.' && current[0] == '.') {
                        st.pop();
                        st.pop();
                    }
                    
                    st.pop();
                }
            } else if(words[i] == "/") {
                if(st.size() > 0 && st.top() != "/" || st.size() == 0) st.push("/");
            } else {
                st.push(words[i]);
            }
        }
        
        while(st.top() == "/" && st.size() > 1) st.pop();
        
        vector<string> aux;
        while(!st.empty()) {
            aux.push_back(st.top());
            st.pop();
        }
        reverse(aux.begin(), aux.end());
        for(auto i : aux) ans += i;
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}