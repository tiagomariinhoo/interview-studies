#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/
 * 
 * Basically this problem is about implement a trie
 * 
 * The only problem is that it's allowed search with words that contains '.', and for this
 * u can use any letter for this position
 * 
 * The solution is just implement a normal Trie but for search, u need to do a dfs for
 * try all letters when find a '.'
 * 
 * The complexity time is:
 * O(alphabet_size * word len * number of words) to create all trie
 * Linear time for insert / delete / searching
 */ 

class WordDictionary {
public:
    
    static const int ALPHABET_SIZE = 26;
    
    struct TrieNode {
        TrieNode *children[ALPHABET_SIZE];
        bool endOfWord;
    };
    
    TrieNode *createNode() {
        TrieNode *newNode = new TrieNode();
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }    
        newNode->endOfWord = false;
        
        return newNode;
    }
    
    TrieNode *head;
    
    WordDictionary() {
        head = createNode();
    }
    
    void addWord(string word) {
        TrieNode *auxNode = head;
        
        for(int i = 0 ; i < word.size(); i++) {
            int aux = word[i] - 'a';
            if(auxNode->children[aux] == NULL) {
                auxNode->children[aux] = createNode();
            }
            auxNode = auxNode->children[aux];
        }
        
        auxNode->endOfWord = true;
    }
    
    bool ans = false;
    
    void dfs(TrieNode *node, int pos, string word) {
        if(node->endOfWord == true && word.size() == pos) {
            ans = true;
            return ;
        }
        if(pos == word.size()) return ;
        if(ans == true) return ;
        
        if(word[pos] == '.') {
            for(int i = 0 ; i < ALPHABET_SIZE; i++) {
                if(node->children[i] != NULL) {
                    dfs(node->children[i], pos + 1, word);
                }
            }
        } else {
            if(node->children[word[pos] - 'a'] != NULL) {
                dfs(node->children[word[pos] - 'a'], pos + 1, word);
            }   
        }
    }
    
    bool search(string word) {
        ans = false;
        
        dfs(head, 0, word);
        
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}