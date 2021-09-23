#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;

/**
 * TRIE IMPLEMENTATION (Prefix Tree)
 * 
 * Insert
 * Every char of the input key is inserted as an individual Trie Node.
 * 
 * Insert and search costs O(key_length)
 * The Memory Requirement is O(ALPHABET_SIZE * key_length * N)
 * Where N is the number of keys in Trie
 */ 

struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  bool endOfWord;
};

struct TrieNode *createNode() {
  TrieNode *newNode = new TrieNode;

  newNode->endOfWord = false;

  for (int i = 0; i < ALPHABET_SIZE; i++) {
    newNode->children[i] = NULL;
  }

  return newNode;
}

void insert(TrieNode *root, string key) {
  TrieNode *auxNode = root;

  for (int i = 0; i < key.size(); i++) {
    int index = key[i] - 'a';
    if(!auxNode->children[index]) {
      auxNode->children[index] = createNode();
    }

    auxNode = auxNode->children[index];
  }

  auxNode->endOfWord = true;
}

bool search(TrieNode *root, string key) {
  TrieNode *auxNode = root;

  for (int i = 0; i < key.size(); i++) {
    int index = key[i] - 'a';
    if(!auxNode->children[index]) {
      return false;
    }

    auxNode = auxNode->children[index];
  }

  return (auxNode->endOfWord);
}

int main() {

  vector<string> keys = {"the", "a", "there","answer", "any", "by","bye", "their" };

  int n = keys.size();
  struct TrieNode *root = createNode();
  //Build Trie
  for (int i = 0; i < keys.size(); i++) {
    insert(root, keys[i]);
  }

  cout << search(root, "the") << endl;

  return 0;
}