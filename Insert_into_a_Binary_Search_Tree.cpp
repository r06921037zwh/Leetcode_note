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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        
        TreeNode* p = root;
        while(true){
            if(val > p->val){
                if(p->right == nullptr){
                    p->right = new TreeNode(val);
                    break;
                }
                p = p->right;
            }else{
                if(p->left == nullptr){
                    p->left = new TreeNode(val);
                    break;
                }
                p = p->left;
            }
        }
        return root;
    }
};
