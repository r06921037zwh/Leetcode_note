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
#include <iterator> 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
    template<typename InputIterator>
    TreeNode* buildTreeHelper(InputIterator in_first, InputIterator in_last, InputIterator post_first, InputIterator post_last){
        if(in_first == in_last) return nullptr;
        if(post_first == post_last) return nullptr;
        
        // root located in the last node of postorder
        TreeNode* root = new TreeNode(*prev(post_last));
        auto inorder_root = std::find(in_first, in_last, *prev(post_last));
        int leftSize = std::distance(in_first, inorder_root);
        
        root->left = buildTreeHelper(in_first, next(in_first, leftSize), post_first, next(post_first, leftSize));
        root->right = buildTreeHelper(next(in_first, leftSize+1), in_last, next(post_first, leftSize), prev(post_last));
        
        return root;
    }
};
