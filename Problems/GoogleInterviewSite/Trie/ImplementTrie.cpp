#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(3*1e5 + 5)
#define MAXL 20
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 9)
#define MOD2 (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, lli> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

class Trie {
public:

    static const int ALPHABET_SIZE = 26;
    
    struct TrieNode {
        TrieNode *children[ALPHABET_SIZE];
        bool endOfWord;
    };
    
    TrieNode *root;
    
    TrieNode *createNode() {
        TrieNode *newNode = new TrieNode;
        newNode->endOfWord = false;
        
        for(int i=0;i<ALPHABET_SIZE;i++) {
            newNode->children[i] = NULL;
        }
        
        return newNode;
    }
    
    Trie() {
        root = createNode();
    }
    
    void insert(string word) {
        TrieNode *auxNode = root;
        
        for(int i=0;i<word.size();i++) {
            if(!auxNode->children[word[i]-'a']) {
                auxNode->children[word[i]-'a'] = createNode();
            }
            
            auxNode = auxNode->children[word[i]-'a'];
        }
        
        auxNode->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *auxNode = root;
        
        for(int i=0;i<word.size();i++) {
            int index = word[i] - 'a';
            
            if(auxNode->children[index]) {
                auxNode = auxNode->children[index];
            } else return false;
        }
        
        return auxNode->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *auxNode = root;
        
        for(int i=0;i<prefix.size();i++) {
            int index = prefix[i] - 'a';
            
            if(auxNode->children[index]) {
                auxNode = auxNode->children[index];
            } else return false;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}