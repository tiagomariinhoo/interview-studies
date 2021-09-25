#include <bits/stdc++.h>

using namespace std;

string input = "abpkangaraopplee";
vector<string> words = {"able", "ale", "apple", "bale", "kangaroo"};

void solution() {
  string ans = "";


  for(auto word : words) {
    int a = 0;
    for(auto c : input) {
      if(a < word.size() && c == word[a]) {
        a++;
      }
    }

    if(a == word.size() && word.size() > ans.size()) {
      // cout << word << endl;
      ans = word;
    }
  }
  
  cout << ans << endl;
}

int main() {

  solution();

  return 0;
}