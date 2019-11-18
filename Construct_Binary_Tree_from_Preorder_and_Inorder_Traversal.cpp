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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
    template <typename InputIterator>
    TreeNode* buildTreeHelper(InputIterator pre_first, InputIterator pre_last,                                     InputIterator in_first, InputIterator in_last){
        if(pre_first == pre_last) return nullptr;
        if(in_first == in_last) return nullptr;
        
        // first node of preorder is root
        TreeNode* root = new TreeNode(*pre_first);
        
        // find the root node in inorder
        auto inorder_Root = std::find(in_first, in_last, *pre_first);
        int leftSize = std::distance(in_first, inorder_Root);
        
        root->left = buildTreeHelper(next(pre_first), next(pre_first, leftSize+1),
                                    in_first, next(in_first, leftSize));
        root->right = buildTreeHelper(next(pre_first, leftSize+1), pre_last,
                                     next(inorder_Root), in_last);
        
        return root;
    }
    // ref: http://www.csie.ntnu.edu.tw/~u91029/BinaryTree.html
};
