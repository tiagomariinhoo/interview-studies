#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * 
 * It's a interesting problem. Basically you need to serialize a binary tree, my approach was:
 * Serialize the tree like:
 * if u have:
 * 1 -> 2,3
 * 2 -> *
 * 3 -> 4, 5
 * 4 -> *
 * 5 -> 8
 * 
 * I can write the tree like:
 * 1 , 2 , 3 / 2, * , * / 3 , 4 , 5 / 4, *, * / 5, *, *
 * 
 * And I just need to read this string where the first element is the current root and the 
 * others are just the childrens
 * The problem can be solved using just a dfs
 */ 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        
        stack<TreeNode*> st;
        st.push(root);
        
        string ans = "";
        
        while(!st.empty()) {
            TreeNode* topElement = st.top();
            string aux = to_string(topElement->val) + ",";
            st.pop();
            
            if(topElement->right != NULL) {
                aux += to_string(topElement->right->val) + ",";
                st.push(topElement->right);
            } else {
                aux += "*,";
            }
            
            if(topElement->left != NULL) {
                aux += to_string(topElement->left->val) + "";
                st.push(topElement->left);
            } else {
                aux += "*";
            }
            
            ans += aux + "/";
        }
        cout << ans << endl;
        
        return ans;
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        
        vector<pair<string, pair<string, string > > > nodes;
        
        for(int i = 0; i < data.size(); i++) {
            string number = "";
            pair<string, pair<string, string> > node;
            node.first = ".";
            node.second.first = ".";
            node.second.second = ".";
            bool at = false;
            for(int j = i; j < data.size();j++) {
                if(data[j] == '/') {
                    node.second.first = number;
                    i = j;
                    break;
                } else if(data[j] == ',') {
                    if(node.first == ".") {
                        node.first = number;
                    } else if(node.second.first == ".") {
                        node.second.second = number;
                    }
                    number = "";
                    continue;
                }
                number += data[j];
            }
            // cout << node.first << " - " << node.second.first << " - " << node.second.second << endl;
            nodes.push_back(node);
            
        }
        
        TreeNode *root = new TreeNode();
        root->val = stoi(nodes[0].first);
        stack<TreeNode*> st;
        st.push(root);
        
        int i = 0;
        while(!st.empty()) {
            TreeNode *element = st.top();
            st.pop();
            
            if(element != NULL) {
                cout << element->val << endl;
                cout << nodes[i].first << " - " << nodes[i].second.first << " - " << nodes[i].second.second << endl;
            }
            
              
            if(nodes[i].second.second != "*") {
                element->right = new TreeNode(stoi(nodes[i].second.second));
                st.push(element->right);
            } else element->right = NULL;
                
            
            if(nodes[i].second.first != "*") {
                element->left = new TreeNode(stoi(nodes[i].second.first));
                st.push(element->left);
            } else element->left = NULL;
            
            i++;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  
  return 0;
}