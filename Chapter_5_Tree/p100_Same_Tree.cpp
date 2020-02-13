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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL && q != NULL) return false;
        else if(q == NULL && p != NULL) return false;
        
        return q->val == p->val && isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
    }
};
