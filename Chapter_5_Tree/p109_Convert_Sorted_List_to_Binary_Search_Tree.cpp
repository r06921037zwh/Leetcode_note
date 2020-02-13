/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
# Top-Down Approach
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return BuildBST(head, listLength(head));
    }
    
    TreeNode* BuildBST(ListNode* node, int length){
        if(length == 0) return nullptr;
        if(length == 1) return new TreeNode(node->val);
        
        TreeNode* root = new TreeNode(moveForward(node, length/2)->val);
        root->left = BuildBST(node, length/2);
        root->right = BuildBST(moveForward(node, length/2 + 1), (length-1)/2);
        return root;
    }
    
    int listLength(ListNode* node){
        int n = 0;
        while(node){
            node = node->next;
            n += 1;
        }
        return n;
    }
    
    ListNode* moveForward(ListNode* node, int step){
        while(step){
            node = node->next;
            step--;
        }
        return node;
    }
};
