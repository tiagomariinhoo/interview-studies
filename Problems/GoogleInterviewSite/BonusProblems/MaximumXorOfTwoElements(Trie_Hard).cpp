#include <bits/stdc++.h>
using namespace std;

/**
 * https://iq.opengenus.org/maximum-xor-trie/#:~:text=The%20global%20maximum%20XOR%20is,with%200%2C%20which%20is%2013.
 * 
 * Problem: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/
 * 
 * Basically u just need to find the maximum xor of two numbers.
 * 
 * My solution was using Trie. Where I can insert all the binary numbers (with 30 chars)
 * for each element into my Trie, and for each element, I just need to make a dfs looking
 * for the oposite bit, this will ensure that u're getting the largest number
 * 
 * For example:
 * 01101
 * -> when make the dfs, will start the dfs looking for a 1
 * -> after that for a 0
 * -> 0
 * -> 1
 * -> 0,
 * if there's no oposite number, just go ahead and get the same number to try
 * the next one
 */ 

class Solution {
public:
   struct TrieNode {
  TrieNode *zero;
  TrieNode *one;

  bool endOfWord;
};

TrieNode *head = NULL;
long long int ans = 0;

TrieNode *createNode() {
  TrieNode *newNode = new TrieNode;
  newNode->zero = NULL;
  newNode->one = NULL;
  newNode->endOfWord = false;

  return newNode;
}

void insert(vector<int> vec) {
  TrieNode *aux = head;

  for(int i = 0; i < vec.size(); i++) {
    // cout << vec[i] << " ";
    if(!vec[i]) {
      if(aux->zero == NULL)
        aux->zero = createNode();

      aux = aux->zero;
    } else {
      if(aux->one == NULL)
        aux->one = createNode();

      aux = aux->one;
    }
  }
  // cout << endl;

  aux->endOfWord = true;
}

vector<int> decimalToBinary(int number) {
  vector<int> aux;
  for(int i=30;i>=0;i--) {
    if(number & (1 << i)) {
      aux.push_back(1);
    } else {
      aux.push_back(0);
    }
  }

  return aux;
}

vector<int> currentBinary;

void dfs(int idx, TrieNode *node, long long int mask) {
  if(idx == currentBinary.size()) {
    // cout << mask << endl;
    ans = max(ans, mask);
    return ;
  }

  if(currentBinary[idx] == 0) {
    if(node->one != NULL) {
      mask |= (1 << (30 - idx));
      dfs(idx + 1, node->one, mask);
    } else if(node->zero != NULL){
      dfs(idx + 1, node->zero, mask);
    }
  } else {
    if(node->zero != NULL) {
      mask |= (1 << (30 - idx));
      dfs(idx + 1, node->zero, mask);
    } else if(node->one != NULL){
      dfs(idx + 1, node->one, mask);
    }
  }
}

bool find(vector<int> binary) {
  TrieNode *aux = head;

  for(int i = 0; i < binary.size(); i++) {
    cout << i << " - " << binary[i] << endl;
    if(binary[i] == 0) {
      if(aux->zero) {
        aux = aux->zero;
      } else {
        return false;
      }
    } else {
      if(aux->one) {
        aux = aux->one;
      } else {
        return false;
      }
    }
  }

  return aux->endOfWord;
}
    
    int findMaximumXOR(vector<int>& nums) {
         // vector<int> vec = {3, 10, 5, 25, 2, 8};
        head = new TrieNode();

         for(auto i : nums) {
            insert(decimalToBinary(i));
          }

          for(auto i : nums) {
            currentBinary = decimalToBinary(i);
            TrieNode *aux = head;

            dfs(0, aux, 0LL);
          }

          return ans;
    }
};



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}