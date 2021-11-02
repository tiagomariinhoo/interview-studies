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

class Solution {
public:
    
    static const int ALPHABET_SIZE = 26;
    string answer = "";
    
    struct TrieNode {
        TrieNode *children[ALPHABET_SIZE];
        bool endOfWord;
        int quantity;
    };
    
    TrieNode *root;
    
    TrieNode *createNode() {
        TrieNode *newNode = new TrieNode;
        newNode->endOfWord = false;
        newNode->quantity = 1;
        for(int i=0;i<ALPHABET_SIZE;i++) {
            newNode->children[i] = NULL;
        }
        
        return newNode;
    }
    
    void insert(string word) {
        TrieNode *auxNode = root;
        
        for(int i=0;i<word.size();i++) {
            int index = word[i] - 'a';
            if(!auxNode->children[index]) {
                auxNode->children[index] = createNode();
            } else {
                auxNode->children[index]->quantity++;
            }
            
            auxNode = auxNode->children[index];
        }
        
        auxNode->endOfWord = true;
    }
    
    void solve(TrieNode *node, int sz, string aux) {
        if(aux.size() > answer.size()) answer = aux;
        
        for(int i=0;i<ALPHABET_SIZE;i++) {
            if(node->children[i])
            if(node->children[i] && node->children[i]->quantity <= (sz) && node->children[i]->endOfWord) {
                char auxChar = i + 'a';
                solve(node->children[i], sz - 1, aux + auxChar);
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        root = createNode();
        
        for(auto i : words) {
            insert(i);
        }
         
        for(int i=0;i<ALPHABET_SIZE;i++) {
            if(root->children[i] && root->children[i]->endOfWord) {
                char auxChar = i + 'a';
                string auxx(1, auxChar);
                solve(root->children[i], root->children[i]->quantity - 1, auxx);
            }
        }
        
        return answer;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  return 0;
}