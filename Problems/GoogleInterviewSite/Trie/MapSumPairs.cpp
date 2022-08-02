#include <bits/stdc++.h>
using namespace std;
 
/**
 * 
 * Just using a normal trie, just keep
 * the map updated with the value for each
 * string and when search/add some string,
 * just use the current valueSum for each node
 * 
 * Complexity: O(W * L) for build trie,
 * 
 * And linear time to search the string, according
 * to the size of the string
 */ 

class MapSum {
public:
    const static int ALPHABET_SIZE = 26;
    
    struct TrieNode {
        TrieNode* children[ALPHABET_SIZE];
        int quantity;
        int valuesSum;
    };
    
    map<string, int> wordValue;
    
    TrieNode *root;
    
    TrieNode* createNode() {
        TrieNode *auxNode = new TrieNode();
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            auxNode->children[i] = NULL;
        }    
        auxNode->quantity = 0;
        auxNode->valuesSum = 0;
        
        return auxNode;
    }
    
    MapSum() {
        root = createNode();
    }
    
    void insert(string key, int val) {
        TrieNode *auxNode = root;
        int auxVal = 0;
        
        if(wordValue[key] != 0) {
            auxVal = wordValue[key];
        }
        
        for(int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';
            if(!auxNode->children[idx]) {
                auxNode->children[idx] = createNode();
            }
            
            auxNode->children[idx]->quantity++;
            auxNode->children[idx]->valuesSum += val - auxVal;
            auxNode = auxNode->children[idx];
        }
        
        wordValue[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode *auxNode = root;
        bool at = false;
        for(int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if(auxNode->children[idx]) {
                auxNode = auxNode->children[idx];  
            } else {
                at = true;
            }
        }
        
        if(at) {
            return 0;
        }
        
        return auxNode->valuesSum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}