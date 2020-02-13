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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        queue<TreeNode*> Q, Q_next;
        bool left_to_right = true;
        
        if(root){
            Q.push(root);
        } else{
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
            if(!left_to_right){
                reverse(level_result.begin(), level_result.end());
            }
            results.push_back(level_result);
            
            left_to_right = !left_to_right;
            swap(Q, Q_next);
        }
        return results;
    }
};
