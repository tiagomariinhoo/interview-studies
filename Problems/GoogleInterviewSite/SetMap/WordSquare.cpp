#include <bits/stdc++.h>

using namespace std;

// vector<string> input = {"abcd", "bnrt", "crmy", "dtye"};
vector<string> input = {"area", "ball", "dear", "lady", "lead", "yard"};
// string input[] = {"abcd", "bnrt", "crmy", "dtye"};

// O (K * |size of word|)

bool solution(vector<string> currentInput) {

  if(currentInput.size() == 0) return false;
  if(currentInput.size() != currentInput[0].size()) return false;

  vector<string> outputAns;

  for(int i = 0; i < currentInput[0].size(); i++) {
    string aux = "";
    for(int j = 0; j < currentInput.size(); j++) {
      aux += currentInput[j][i];
    }

    outputAns.push_back(aux);
  }

  for (int i = 0; i < currentInput.size(); i++) {
    if(currentInput[i] != outputAns[i]) return false;
  }

  return true;

}

void buildInput(int idx, vector<string> currentInput) {

  sort(currentInput.begin(), currentInput.end());

  do {

    int ans = solution(currentInput);
    if(ans) {
      cout << "Found a solution!" << endl;
      for(auto i : currentInput) {
        cout << i << " ";
      }
      cout << endl;
    }
  } while(next_permutation(currentInput.begin(), currentInput.end()));

  if(idx == input.size()) return ;

  buildInput(idx + 1, currentInput);
  currentInput.push_back(input[idx]);
  buildInput(idx + 1, currentInput);
}

/**
 * The first problem is check if a word square
 * 
 * The second problem is get all possibles list of words
 * that can be a word square
 * 
 * The solution will take k^2 * nCr (N, k) * K!
 */ 

int main() {

  vector<string> currentInput;
  buildInput(0, currentInput);

  return 0;
}