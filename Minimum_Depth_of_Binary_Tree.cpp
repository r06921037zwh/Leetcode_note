/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursion Version
#include <algorithm>
class Solution {
public:
    int minDepth(TreeNode* root) {
        return minDepthSearch(root, false);
    }
    int minDepthSearch(TreeNode* node, bool hasbrother){
        if(!node){
            if(!hasbrother) return 0;
            else return INT_MAX;
        }
        
        return 1 + min(minDepthSearch(node->left, node->right != nullptr), minDepthSearch(node->right, node->left != nullptr));
    }
};
