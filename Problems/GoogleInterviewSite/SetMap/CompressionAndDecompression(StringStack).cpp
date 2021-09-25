#include <bits/stdc++.h>

using namespace std;

string s;
int pos = 0;


int main() {

  cin >> s;

  /**
   * https://techdevguide.withgoogle.com/resources/former-interview-question-compression-and-decompression/#!
   * 
   * https://leetcode.com/problems/decode-string/
   * 
   * Possible solution
   * 
   * Stack all chars and when find an ]
   * pop the stack until find an [
   * after this, pop until get all numbers
   */
  
  stack<char> st;
  string ans = "";

  for (int i = 0; i < s.size(); i++) {
    if(s[i] == ']') {
      string aux = "";
      while(st.top() != '[') {
        aux += st.top();
        st.pop();
      }

      st.pop();

      string mulString = "";

      while(!st.empty() && st.top() >= '0' && st.top() <= '9') {
        mulString += st.top();
        st.pop();
      }

      reverse(mulString.begin(), mulString.end());
      reverse(aux.begin(), aux.end());

      if(mulString == "") continue;

      int mul = stoi(mulString);

      for(int j=0;j<mul;j++) {
        for(auto j : aux) {
          st.push(j);
        }
      }
    } else {
      st.push(s[i]);
    }
  }

  while(!st.empty()) {
    ans += st.top();
    st.pop();
  }

  reverse(ans.begin(), ans.end());

  cout << ans << endl;

  return 0;
}