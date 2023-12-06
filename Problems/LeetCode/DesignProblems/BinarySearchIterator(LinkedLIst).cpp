/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:

    struct Node {
        int val;
        Node *next;
    };

    Node *head = NULL, *tail = NULL;

    void createNode(int val) {
        if (head == NULL) {
            head = new Node();
            head->val = val;
            head->next = NULL;
            tail = head;
        } else {
            Node *aux = new Node();
            aux->val = val;
            aux->next = NULL;
            tail->next = aux;
            tail = tail->next;
        }
    }

    BSTIterator(TreeNode* root) {
        dfs(root);
    }

    void dfs(TreeNode *node) {
        if (node == NULL) return;
        dfs(node->left);
        createNode(node->val);
        dfs(node->right);
    }
    
    int next() {
        if (head != NULL) {
            int a = head->val;
            head = head->next;
            return a;
        }

        return 0;
    }
    
    bool hasNext() {
        if (head != NULL) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */