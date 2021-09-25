#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/backspace-string-compare/submissions/
 */ 

bool solution(string s, string t) {

  stack<char>stackForS;
  stack<char>stackForT;

  for(auto i : s) {
    if(i == '#') {
      if(!stackForS.empty()) {
        stackForS.pop();
      }
    } else stackForS.push(i);
  }

  for(auto i : t) {
    if(i == '#') {
      if(!stackForT.empty()) {
        stackForT.pop();
      }
    } else stackForT.push(i);
  }

  if(stackForS.size() != stackForT.size()) return false;

  while(!stackForS.empty()) {
    if(stackForS.top() != stackForT.top()) return false;
    stackForS.pop();
    stackForT.pop();
  }

  return true;
}


int main() {

  string s = "ab#c";
  string t = "ad#c";
  
  cout << solution(s, t) << endl;


  return 0;
}