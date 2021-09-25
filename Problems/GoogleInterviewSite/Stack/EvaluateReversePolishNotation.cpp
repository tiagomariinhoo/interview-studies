#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/
 */ 

int solution(vector<string> tokens) {
  stack<int> numberStack;
  int ans = 0;

  for(auto i : tokens) {
    if(i == "+") {
      int firstNumber = numberStack.top();
      numberStack.pop();
      int secondNumber = numberStack.top();
      numberStack.pop();

      numberStack.push(firstNumber + secondNumber);

    } else if(i == "-") {
      int firstNumber = numberStack.top();
      numberStack.pop();
      int secondNumber = numberStack.top();
      numberStack.pop();

      numberStack.push(secondNumber - firstNumber);
      
    } else if(i == "*") {
      int firstNumber = numberStack.top();
      numberStack.pop();
      int secondNumber = numberStack.top();
      numberStack.pop();

      numberStack.push(firstNumber * secondNumber);

    } else if(i == "/") {
      int firstNumber = numberStack.top();
      numberStack.pop();
      int secondNumber = numberStack.top();
      numberStack.pop();
      numberStack.push(secondNumber / firstNumber);

    } else {
      int number = stoi(i);
      numberStack.push(number);
    }
  }

  return numberStack.top();
}

int main() {

  vector<string> tokens = {"4","13","5","/","+"};
  cout << solution(tokens) << endl;

  return 0;
}