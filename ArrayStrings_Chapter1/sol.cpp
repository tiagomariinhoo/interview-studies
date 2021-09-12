#include <bits/stdc++.h>
using namespace std;

void firstSolution(string input) {
  /**
   * Check if string is an ASCII string or a Unicode string
   * 
   */ 

  //n² solution
  // for(int i = 0; i < input.size(); i++) {
  //   for(int j = 0; j < input.size(); j++) {
  //     if(i == j) continue;

  //     if(input[i] == input[j]) {
  //       cout << "Not unique n2" << endl;
  //       return ;
  //     }
  //   }
  // }

  // cout << "Unique! n2" << endl;

  // set<int> chars;

  // //NLogN

  // //N
  // for(int i = 0; i < input.size(); i++) {
  //   if(chars.find(input[i]) != chars.end()) {
  //     cout << "Not unique NLogN" << endl;
  //     return;
  //   }

  //   //log N
  //   chars.insert(input[i]);
  // }

  //N Log N
  // cout << "Unique! NLogN" << endl;


  //N solution
  // int chars[300];

  // memset(chars, 0, sizeof (chars));

  // for(int i = 0; i < input.size(); i++) {
  //   if(chars[input[i] - 'a'] > 0) {
  //     cout << "not unique" << endl;
  //     return ;
  //   }

  //   chars[input[i] - 'a'] = 1;
  // }

  // cout << "is unique!" << endl;

  //Solution decreasing space complexity using bit

  int mask = 0;

  for(int i = 0; i < input.size(); i++) {
    if((1 << (input[i] - 'a') & mask)) {
      cout << "not unique" << endl;
      return ;
    }

    int position = (1 << (input[i] - 'a'));

    mask |= position;
  }

  cout << "Unique!" << endl;
}

void secondSolution(string stringOne, string stringTwo) {
  //N Log N solution
  sort(stringOne.begin(), stringOne.end());
  sort(stringTwo.begin(), stringTwo.end());

  if(stringOne.size() != stringTwo.size()) {
    cout << "is not a permutation!" << endl;
    return ;
  }

  for(int i = 0; i < stringOne.size(); i++) {
    if(stringOne[i] != stringTwo[i]) {
      cout << "is not a permutation!" << endl;
      return ;
    }
  }

  cout << "is a permutation" << endl;

  /**
   * There is another solution that can works
   * in linear time
   * 
   * We just need to build an array that I can
   * store the indexes
   */
  
}

void thirdSolution(string input) {
  // This can be used to replace one to one
  // replace(input.begin(), input.end(), ' ', '%');

  // Linear time solution
  string answer = "";
  for(auto c : input) {
    if(c == ' ') {
      answer += "%20";
    } else answer += c;
  }

  cout << "Output: " << answer << endl;
}

void fourthSolution(string input) {
  /**
   * abcba
   */

  for(auto &c : input) {
    c = tolower(c);
  }

  int chars[500];
  memset(chars, 0, sizeof chars);
  for(int i=0;i<input.size();i++) {
    chars[input[i] - ' ']++;
    cout << input[i]-' ' << endl;
  }

  int at = 0;
  for(int i=1;i<300;i++) {
    if(chars[i]%2!=0) {
      at++;
    }
  }

  cout << at << endl;
  if(at > 1) {
    cout << "Cannot be palindrome" << endl;
    return ;
  }

  cout << "Can be a palindrome" << endl;
}

void fifthSolution(vector< vector<int> >  input) {
  vector <vector<int> > answer;

  // Rotate right
  for (int i = 0; i < input.size(); i++) {
    vector<int> aux;
    for (int j = 0; j < input[i].size(); j++) {
      aux.push_back(input[j][i]);
    }
    answer.push_back(aux);
  }

  // To rotate left
  // reverse(answer.begin(), answer.end());

  for(auto i : answer) {
    for(auto j : i) {
      cout << j << " ";
    } cout << endl;
  }
}

void sixthSolution(string s1, string s2) {
  if(s1.size() != s2.size()) {
    cout << "is not rotation" << endl;
  }

  string temp = s1 + s1;

  // The string find taks a linear time
  if(temp.find(s2) != string::npos) {
    cout << "is rotation" << endl;
  }
}
int main() {

  /**
   * First Problem
   * 
   * Implement an algorithm to determine if a string has
   * all unique chars. What if u cannot use additional 
   * data structures?
   */

  cout << "----- First Problem -----" << endl;
  firstSolution("aabc");

  /**
   * Second problem
   * 
   * Given two strings, write a method to decide if one is 
   * a permutation of the other
   */

  cout << "----- Second Problem -----" << endl;
  secondSolution("abcd", "dcbfa");

  /**
   * Third problem
   * 
   * Write a method to replace all spaces in a string with '%20'
   * 
   * "Mr John Smith" -> "Mr%20John%20Smith"
   */

  cout << "----- Third Problem -----" << endl;
  // string input;
  // getline(cin, input);
  thirdSolution("Mr John Smith");

  /**
   * Fourth problem
   * 
   * Given a string
   * write a function to check if its a permutation of a palindrome
   * 
   * Tact Coa
   * -> taco cat
   */

  cout << "----- Fourth Problem -----" << endl;
  // string input;
  // getline(cin, input);
  fourthSolution("Tact Coa");

  /**
   * Fifth problem
   * 
   * Rotate Matrix
   * 
   * Matrix:
    1  2  3
    4  5  6
    7  8  9
    Output:
    3  6  9 
    2  5  8 
    1  4  7 
   */

  cout << "----- Fifth Problem -----" << endl;
  // string input;
  // getline(cin, input);
  vector< vector<int> > input = {
    {1, 2, 3},
    {1, 2, 3},
    {1, 2, 3},
  };

  fifthSolution(input);

  /**
   * Sixth problem
   * 
   * String Rotation
   * Assume u have a method isSubstring whick checks
   * if one word is substring of another
   * 
   * waterbottle is a rotation of erbottlewat
   */

  cout << "----- Sixth Problem -----" << endl;
  // string input;
  // getline(cin, input);

  sixthSolution("waterbottle", "erbottlewat");

  return 0;
}