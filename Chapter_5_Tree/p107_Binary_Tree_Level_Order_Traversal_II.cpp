/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        queue<TreeNode*> Q, Q_next;
        
        if(root){
            Q.push(root);
        }
        else{
            return results;
        }        
        
        while(!Q.empty()){
            vector<int> level_result;
            while(!Q.empty()){
                TreeNode* tmp = Q.front();
                Q.pop();
                level_result.push_back(tmp->val);
                
                if(tmp->left) Q_next.push(tmp->left);
                if(tmp->right) Q_next.push(tmp->right);
            }
            results.push_back(level_result);
            swap(Q, Q_next);
        }
        reverse(results.begin(), results.end()); 
        return results;
    }
};
