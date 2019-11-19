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
public:
    // nullptr means infinite large/small
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);
    }
    
    bool isValidBSTHelper(TreeNode* node, int* lower, int* upper){
        if (node == nullptr) return true;
        if((lower && node->val <= *lower) || (upper && node->val >= *upper)) return false;
        
        return isValidBSTHelper(node->left, lower, &node->val) && isValidBSTHelper(node->right, &node->val, upper);
        
    }
};
