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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        queue<pair<TreeNode*, int>> Q;
        
        if(!root){
            return results;
        }
        Q.push(make_pair(root, 0));
        while(!Q.empty()){
            TreeNode* node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if(Q.empty() || (!Q.empty() && Q.front().second > depth)){
                results.push_back(node->val);
            }
            
            if(node->left){
                Q.push(make_pair(node->left, depth+1));
            }
            if(node->right){
                Q.push(make_pair(node->right, depth+1));
            }
        }
               
        return results;
    }
};
