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
    bool judgeSymm(TreeNode* left, TreeNode* right){
        if(left == NULL){
            return right == NULL;
        }
        if(right == NULL){
            return left == NULL;
        }
        if(right->val != left->val){
            return false;
        }
        if(!judgeSymm(left->left, right->right)){
            return false;
        }
        if(!judgeSymm(left->right, right->left)){
            return false;
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return judgeSymm(root->left, root->right);
    }
};
