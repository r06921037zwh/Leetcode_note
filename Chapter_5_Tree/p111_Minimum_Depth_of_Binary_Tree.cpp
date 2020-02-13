/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursion Version
#include <algorithm>
class Solution {
public:
    int minDepth(TreeNode* root) {
        return minDepthSearch(root, false);
    }
    int minDepthSearch(TreeNode* node, bool hasbrother){
        if(!node){
            if(!hasbrother) return 0;
            else return INT_MAX;
        }
        
        return 1 + min(minDepthSearch(node->left, node->right != nullptr), minDepthSearch(node->right, node->left != nullptr));
    }
};


/*Iterative Version*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int result = INT_MAX;
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 1));
        
        while(!s.empty()){
            TreeNode* node = s.top().first;
            int depth = s.top().second;
            s.pop();
            
            if(!node->left && !node->right){
                result = min(depth, result);
            }
            
            if(node->left && depth < result) {
                s.push(make_pair(node->left, depth+1));
            }
            
            if(node->right && depth < result) {
                s.push(make_pair(node->right, depth+1));
            }
              
        }
        return result;
    }
};
