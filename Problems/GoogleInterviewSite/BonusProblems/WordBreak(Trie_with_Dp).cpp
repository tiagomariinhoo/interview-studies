#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/word-break/submissions/
 * 
 * Beautiful problem using Trie and Dynamic Programming
 * 
 * After build a Trie using the dict, just do a top down
 * dfs and using pair<pos, node> for memoization
 * 
 * 
 * complexity time: Sum of all len dict to make trie
 * s.size() + word dict sizes
 */ 

class Solution {
public:
    bool ans = false;
    string globalString;
    
    static const int ALPHABET_SIZE = 26;
    
    struct TrieNode {
        TrieNode *children[ALPHABET_SIZE];
        bool endOfWord;
    };
    
    TrieNode *head;
    
    TrieNode *createNode() {
        TrieNode *newNode =  new TrieNode();
        newNode->endOfWord = false;
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
        
        return newNode;
    }
    
    void insert(string word) {
        TrieNode *aux = head;
        for(auto i : word) {
            int current = i - 'a';
            if(aux->children[current] == NULL) {
                aux->children[current] = createNode();
            }
            
            aux = aux->children[current];
        }
        aux->endOfWord = true;
    }
    
    map<pair<int, TrieNode*>, int>  memo;
    
    int solve(int pos, TrieNode *currentNode) {
        if(currentNode == NULL) return 2;
        
        if(pos == globalString.size() - 1) {
            if(currentNode->endOfWord) {
                return 1;
            }
            return 2;
        }
        
        if(memo[{pos, currentNode}] != 0) {
            return memo[{pos, currentNode}];
        }
        
        int a = 0, b = 0;
        a = solve(pos + 1, currentNode->children[globalString[pos + 1] - 'a']);
        if(currentNode->endOfWord == true)
            b = solve(pos + 1, head->children[globalString[pos + 1] - 'a']); 
        
        memo[{pos, currentNode}] = (a == 1 | b == 1) ? 1 : 2;
        
        return memo[{pos, currentNode}];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        head = createNode();
        globalString = s;
        
        for(auto i : wordDict) insert(i);
        return solve(0, head->children[s[0] - 'a']) == 1 ? true : false;
    }
};

/**
 * Dp bottom up 
 * Just checking if there's a  i - word.size() with this substring (word) and
 * if dp[i - word.size()] = 1, this indicates that u can reach i - word.size() with a solution
 * 
 * Complexity Time: s.size() * Sum of all dict words
 */

class Solution {
public:
    int dp[301];
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dp[0] = 1;
        
        for(int i = 0 ; i <= s.size(); i++) {
            for(auto word : wordDict) {
                if(word.size() <= i) {
                    if(s.substr(i - word.size(), word.size()) == word) {
                        if(dp[i - word.size()] == 1) dp[i] = 1;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}