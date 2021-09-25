#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/valid-parentheses/submissions/
 * 
 * Just check if the string is a valid parentheses
 */

bool solution(string s) {
  stack<char> st;

  for(auto i : s) {
    if(i == '[' or i == '(' or i == '{') {
      st.push(i);
    } else {
      if(st.empty()) {
        st.push(i);
      }

      if(i == ']' && st.top() == '[') st.pop();
      else if(i == ']' && st.top() != '[') st.push(i);

      if(i == ')' && st.top() == '(') st.pop();
      else if(i == ')' && st.top() != '(') st.push(i);

      if(i == '}' && st.top() == '{') st.pop();
      else if(i == '}' && st.top() != '{') st.push(i);
    }
  }

  return st.empty();
}

int main() {

  string s = "({})";
  
  cout << solution(s) << endl;


  return 0;
}