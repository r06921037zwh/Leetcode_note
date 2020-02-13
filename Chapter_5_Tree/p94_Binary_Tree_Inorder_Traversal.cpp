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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<TreeNode*> s;
        TreeNode* p;
        
        if(root){
            p = root;
        }
        while(!s.empty() || p){
            if(p){
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                results.push_back(p->val);
                p = p->right;
            }
        }
        return results;
    }
};
