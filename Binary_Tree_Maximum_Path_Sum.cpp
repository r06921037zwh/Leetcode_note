/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfsPathSum(root, maxSum);
        return maxSum;
    }
    
    int dfsPathSum(TreeNode* node, int& maxSum){
        if(!node) return 0;
        int l = dfsPathSum(node->left, maxSum);
        int r = dfsPathSum(node->right, maxSum);
        
        int currentSum = node->val;
        if(l > 0) currentSum += l;
        if(r > 0) currentSum += r;
        maxSum = max(currentSum, maxSum);
        
        // only when right or left route > 0, return one of them + current node
        // or just return current node val
        if(max(l, r) > 0) return node->val + max(l, r);
        else return node->val;
    }
};
