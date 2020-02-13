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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        
        TreeNode* p = root;
        while(p){
            if(val == p->val) return p;
            else if(val > p->val){
                p = p->right;
            }else{
                p = p->left;
            }
        }
        return nullptr;
    }
};
