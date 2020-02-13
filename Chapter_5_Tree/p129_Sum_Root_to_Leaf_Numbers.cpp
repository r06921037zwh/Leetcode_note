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
    int sumNumbers(TreeNode* root) {
        return dfsSumNumbers(root, 0);
    }
    int dfsSumNumbers(TreeNode* node, int sum){
        if(!node) return 0;
        if(!node->left && !node->right){
            return sum * 10 + node->val;
        }
        
        return dfsSumNumbers(node->left, sum * 10 + node->val) + dfsSumNumbers(node->right, sum * 10 + node->val);
    }
};
