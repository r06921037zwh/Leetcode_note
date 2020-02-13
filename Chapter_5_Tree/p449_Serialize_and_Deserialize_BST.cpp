/*
For binary search tree, sequentially insert the nodes in preorder will construct exactly the same binary search tree!
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <vector>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        BST_preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        
        vector<TreeNode*> node_vec;
        int val = 0;
        for(int i = 0; i < data.length(); i++){
            if(data[i] == '#'){
                node_vec.push_back(new TreeNode(val));
                val = 0;
            }else{
                val = val * 10 + data[i] - '0';
            }
        }
        
        for(int i = 1; i < node_vec.size(); i++){
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
    
    void change_int_into_string(int val, string &str_val){
        string tmp;
        while(val){
            tmp += val % 10 + '0';
            val /= 10;
        }
        // add the val (string format) reversely into str_val 
        for (int i = tmp.length()-1; i >= 0; i--){
            str_val += tmp[i];
        }
        str_val += '#';
    }
    
    void BST_preorder(TreeNode* node, string &data){
        if(!node) return;
        
        string str_val;
        change_int_into_string(node->val, str_val);
        data += str_val;
        BST_preorder(node->left, data);
        BST_preorder(node->right, data);
    }
    
    void BST_insert(TreeNode* node, TreeNode* inserted_node){
        if(inserted_node->val > node->val){
            if(node->right){
                BST_insert(node->right, inserted_node);
            }else{
                node->right = inserted_node;
            }
        }else{
            if(node->left){
                BST_insert(node->left, inserted_node);
            }else{
                node->left = inserted_node;
            }
 
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
