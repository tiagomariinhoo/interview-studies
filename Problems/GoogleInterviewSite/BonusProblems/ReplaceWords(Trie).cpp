#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/replace-words/submissions/
 * 
 * For each word, just need to dfs the Trie to check prefix
 * Linear time, where N is the size of the sentence
 */ 

class Solution {
public:
    
    static const int ALPHABET_SIZE = 26;
    
    struct TrieNode {
        TrieNode *children[ALPHABET_SIZE];
        string fullWord;
        bool endOfWord;
    };
    TrieNode *head;
    
    TrieNode *createNode() {
        TrieNode *newNode = new TrieNode();
        for(int i=0;i<ALPHABET_SIZE;i++) {
            newNode->children[i] = NULL;
        }
        newNode->endOfWord = false;
        newNode->fullWord = "";
        
        return newNode;
    }    
    
    void insertWord(string word) {
        TrieNode *aux = head;
        for(int i = 0; i < word.size(); i++) {
            if(aux->children[word[i]-'a'] == NULL) {
                aux->children[word[i]-'a'] = createNode();
            }
            
            aux = aux->children[word[i]-'a'];
        }
        aux->fullWord = word;
        aux->endOfWord = true;
    }
    
    string findPrefix(string word) {
        TrieNode *aux = head;
        
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(aux->children[idx] != NULL) {
                aux = aux->children[idx];
            } else {
                return word;
            }
            
            if(aux->endOfWord) {
                return aux->fullWord;
            }
        }
        
        return word;
    }

    vector<string> separateWords(string sentence) {
        vector<string> aux;
        
        string auxString = "";
        for(int i = 0; i < sentence.size(); i++) {
            if(sentence[i] == ' ') {
             aux.push_back(auxString);
                auxString = "";
            } else {
                auxString += sentence[i];
            }
        }
        
        if(auxString.size() > 0) {
            aux.push_back(auxString);
        }
        
        return aux;
    }
        
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words = separateWords(sentence);
        
        map<string, int> qt;
        head = createNode();
        
        for(auto i : dictionary) {
            insertWord(i);
        }
        
        
        string ans = "";
        
        for(int i = 0; i < words.size(); i++) {
            string aux = findPrefix(words[i]);
            
            ans += aux;
            
            if(i < words.size() - 1) ans += " ";
            
            aux = "";
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}