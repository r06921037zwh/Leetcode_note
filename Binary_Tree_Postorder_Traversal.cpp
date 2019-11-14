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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<pair<TreeNode*, bool>> s;
        
        if(root){
           s.push(make_pair(root, false)); 
        }
        while(!s.empty()){
            TreeNode* tmp = s.top().first;
            int visited = s.top().second; 
            s.pop();
            
            if(visited){
                results.push_back(tmp->val);
            }
            else{
                s.push(make_pair(tmp, true));
                if(tmp->right){
                    s.push(make_pair(tmp->right, false));
                }
                if(tmp->left){
                    s.push(make_pair(tmp->left, false));
                }
            }
        }
        return results;
    }
};
