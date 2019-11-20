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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, nums.begin(), nums.end());
    }
    
    template <typename InputIterator>
    TreeNode* buildBST(vector<int>& nums, InputIterator start, InputIterator end){
        int d = distance(start, end);
        if(d <= 0) return nullptr;
        
        auto mid = start + d/2; // mid should be a pointer
        TreeNode* node = new TreeNode(*mid);
        node->left = buildBST(nums, start, mid);
        node->right = buildBST(nums, mid+1, end);
        
        return node;
    }
};
