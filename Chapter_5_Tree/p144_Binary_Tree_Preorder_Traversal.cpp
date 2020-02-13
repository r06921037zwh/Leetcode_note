/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
#include <vector>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<TreeNode*> s;
        
        if(root){
            s.push(root);
        }
        
        while(!s.empty()){
            TreeNode* tmp = s.top();
            s.pop();
            results.push_back(tmp->val);
            
            if(tmp->right){
                s.push(tmp->right);
            }
            if(tmp->left){
                s.push(tmp->left);
            }
            
        }
        return results;
    }
};
