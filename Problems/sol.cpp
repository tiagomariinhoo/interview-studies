#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
  TrieNode *children[ALPHABET_SIZE];
  bool endOfWord;
};

TrieNode *root;

TrieNode *createNode() {
  TrieNode *newNode = new TrieNode();
  newNode->endOfWord = false;

  for(int i = 0; i < ALPHABET_SIZE; i++) {
    newNode->children = NULL;
  }

  return newNode;
}

void addNode(string word) {
  TrieNode *auxNode = root;

  for(int i = 0; i < word.size(); i++) {
    if(!auxNode->children[word[i] - 'a']) {
      auxNode->children[word[i] - 'a'] = createNode();
    }
    auxNode = auxNode->children[word[i] - 'a'];
  }

  auxNode->endOfWord = true;
}

bool search(string word) {
  TrieNode *auxNode = root;

  for(int i = 0; i < word.size(); i++) {
    if(!auxNode->children[word[i] - 'a']) {
      return false;
    }
    auxNode = auxNode->children[word[i] - 'a'];
  }

  return auxNode->endOfWord;
}

bool startsWith(string prefix) {
  TrieNode *auxNode = root;

  for(int i = 0; i < prefix.size();i ++) {
    if(!auxNode->children[prefix[i] - 'a']) {
      break;
    } else {
      if(auxNode->endOfWord) {
        return true;
      }
    }
    auxNode = auxNode->children[prefix[i] - 'a'];
  }

  return false;
}

TrieNode *root = createNode();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  root = createNode();





  return 0;
}