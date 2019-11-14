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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        queue<TreeNode*> Q;
        queue<TreeNode*> Q_next;
        
        if(!root){
            return results;
        }
        Q.push(root);
        
        while (!Q.empty()){
            vector<int> level_result; // store one level result
            while(!Q.empty()){
                TreeNode* node = Q.front();
                Q.pop();
                level_result.push_back(node->val);
                if(node->left){
                    Q_next.push(node->left);
                }
                if(node->right){
                    Q_next.push(node->right);
                }
            }
            results.push_back(level_result);
            swap(Q, Q_next);
        }
        return results;
    }
};
