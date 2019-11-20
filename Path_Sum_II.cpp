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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;        // final results
        vector<int> path;                 // middle results
        pathSum(root, sum, path, paths);
        return paths;
    }
    void pathSum(TreeNode* node, int remain, vector<int>& path, vector<vector<int>>& paths){
        if(!node) return;
        
        path.push_back(node->val);
        if(!node->left && !node->right && remain == node->val){
            paths.push_back(path);
        }
        
        pathSum(node->left, remain - node->val, path, paths);
        pathSum(node->right, remain - node->val, path, paths);
        
        path.pop_back();
    }
};
