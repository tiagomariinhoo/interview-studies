#include <bits/stdc++.h>
using namespace std;

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
  // for(auto i : binary) cout << i << " ";
  // cout << endl;

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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  head = new TrieNode();

  vector<int> vec = {3, 10, 5, 25, 2, 8};

  for(auto i : vec) {
    insert(decimalToBinary(i));
    // vector<int> aux = decimalToBinary(i);
    // cout << i << " - ";
    // for(auto j : aux) cout << j << " ";
    // cout << endl;
  }
  // insert(decimalToBinary(5));
  // insert(decimalToBinary(3));

  // if(find(decimalToBinary(vec[2]))) {
  //   cout << "Achou!" << endl;
  // }

  for(auto i : vec) {
    currentBinary = decimalToBinary(i);
    TrieNode *aux = head;
    // cout << "Element: " << i << endl;
    dfs(0, aux, 0LL);
    // cout << endl;
  }

  // cout << ans << endl;

  return 0;
}

// 11001 - 25
// 00011 - 3
// 01010 - 10
// 00101 - 5
// 00010 - 2
// 01000 - 8