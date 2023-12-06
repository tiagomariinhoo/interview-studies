class Solution {
public:

    /**
        Very interesting problem that can be solved using Trie with Bfs

        The first thing here is implement a Trie to store each Word. It's possible to see how the Trie works here https://www.geeksforgeeks.org/trie-insert-and-search/
        But basically, you just need to make a TrieNode with 2 attributes:
            - TrieNode *children[ALPHABET_SIZE] -> Pointer to the next character 
            - bool endOfWord -> That will indicate if it's a endOfWord
        It's always good to make a help function called createNode(), as the name says, just to create a Node, setting all the pointers to NULL and endOfWord to false
        Also, it's necessary create the insert function to insert all the words given
        Now, we can use the solve function to really solve the problem (oh!), basically we just need to iterate through the board and check if going to the next character (using dx and dy), I'm also going to a Node that's not null (since  it would be a word from our Words vector).

        The code takes
        Complexity time: O (n * m * 4 ^ (word len))
        Auxiliary space: O (words len * word size)

    */

    static const int ALPHABET_SIZE = 26;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    set<string> ans;
    vector<vector<char>> vec;

    // Also called Prefix Tree
    struct TrieNode {
        struct TrieNode *children[ALPHABET_SIZE];
        bool endOfWord;
    };

    struct TrieNode *createNode() {
        TrieNode *newNode = new TrieNode();
        newNode->endOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++) newNode->children[i] = NULL;

        return newNode;
    }

    void insert(TrieNode* root, string word) {
        TrieNode *aux = root;
        for (int i = 0; i < word.size(); i++) {
            int currentChar = word[i] - 'a';
            if (aux->children[currentChar] == NULL) {
                aux->children[currentChar] = createNode();
                aux = aux->children[currentChar];
            } else aux = aux->children[currentChar];
        }

        aux->endOfWord = true;
    }

    void solve(int x, int y, TrieNode *node, string current) {

        if (node == NULL) return ;
        if (node->endOfWord) {
            ans.insert(current);
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            char aux = vec[x][y];
            vec[x][y] = '*';
            if (xx >= 0 and xx < n and yy >= 0 and yy < m && vec[xx][yy] != '*' and node->children[vec[xx][yy] - 'a'] != NULL) {
                solve(xx, yy, node->children[vec[xx][yy] - 'a'], current + vec[xx][yy]);
            }
            vec[x][y] = aux;

        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        vec = board;

        TrieNode *root = createNode();
        
        // This takes O (words.size  * word.size)
        for (auto i : words) {
            insert(root, i);
        }

        // This takes O (n * m * 4 ^ (word len))
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string s;
                s += board[i][j];
                solve(i, j, root->children[board[i][j] - 'a'], s);
            }
        }

        vector<string> anss;

        for (auto i : ans) anss.push_back(i);

        return anss;
    }
};