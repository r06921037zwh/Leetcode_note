/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balancedTreeHeight(root) >= 0;
    }
    /*
        If root is a balanced tree, return height of the tree
        otherwise return -1
    */
    int balancedTreeHeight(TreeNode* root){
        if(!root) return 0;
        
        int left_tree_height = balancedTreeHeight(root->left);
        int right_tree_height = balancedTreeHeight(root->right);
        
        if(left_tree_height < 0 || right_tree_height < 0 || abs(left_tree_height - right_tree_height) > 1){
            return -1;
        }
        return max(left_tree_height, right_tree_height) + 1;
    }
};
