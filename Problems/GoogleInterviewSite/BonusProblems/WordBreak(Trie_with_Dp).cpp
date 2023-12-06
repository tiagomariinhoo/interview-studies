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
    static const int ALPHABET_SIZE = 26;

    /**
        Solution that runs in quadratic time and use Trie + Dp
        Just need to put all the word dict strings into the trie
        and check the String S with a Dfs. The point here is to use
        Dynamic Programming when there's a (idx, node) that was already visited
        
    */

    struct TrieNode {
        TrieNode *next[ALPHABET_SIZE];
        bool endOfWord;
    };

    TrieNode *root;
    bool ans = false;

    TrieNode *createNode() {
        TrieNode *newNode = new TrieNode();
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->next[i] = NULL;
        }

        newNode->endOfWord = false;

        return newNode;
    }

    void insertWord(string s) {
        TrieNode *aux = root;

        for (auto i : s) {
            int current = i - 'a';
            if (aux->next[current] == NULL) {
                aux->next[current] = createNode();
            } 
            aux = aux->next[current];
        }
        aux->endOfWord = true;
    }

    map<pair<int, TrieNode*>, int> memo;
    int dfs(int idx, string s, TrieNode *aux) {
        if (aux == NULL) return 1;
        if (idx == s.size() - 1) {
            if (aux->endOfWord == true) {
                return 2;
            }
            return 1;
        }

        if (memo[{idx, aux}] != 0) {
            return memo[{idx, aux}];
        }

        int next = s[idx + 1] - 'a';
        int a = dfs(idx + 1, s, aux->next[next]);

        if (aux->endOfWord == true) {
            int b = dfs(idx + 1, s, root->next[s[idx + 1] - 'a']);
            if (a == 2 || b == 2) return memo[{idx, aux}] = 2;
        }

        return memo[{idx, aux}] = a;
    }
 
    bool wordBreak(string s, vector<string>& wordDict) {
        root = createNode();
        for (auto i : wordDict) insertWord(i);



        return dfs(0, s, root->next[s[0] - 'a']) == 2 ? true : false;
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