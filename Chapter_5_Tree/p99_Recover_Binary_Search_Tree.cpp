/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        inorder(root);
        
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    // if inorder traversal, find the latter is less than previous
    // then mark the two nodes for exchanging purpose
    void inorder(TreeNode* node){
        if(!node) return;
        inorder(node->left);
        if(prev != NULL && first == NULL && prev->val >= node->val) first = prev;
        if(prev != NULL && first != NULL && prev->val >= node->val) second = node;
        prev = node;
        inorder(node->right);
    }
};
