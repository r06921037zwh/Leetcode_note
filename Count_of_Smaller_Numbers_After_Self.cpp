/*
Solve with Reversed Binary Tree
*/
struct BSTNode{
    int val;
    int count; // how many nodes in left tree
    BSTNode* left;
    BSTNode* right;
    BSTNode(int x) : val(x), left(NULL), right(NULL), count(0) {};
};

#include <vector>
class Solution {
public:
    // cnt_smaller counts the number of nodes smaller than inserted node
    void BST_insert(BSTNode* node, BSTNode* inserted_node, int& cnt_smaller){
        if(inserted_node->val <= node->val){
            node->count++;
            if(node->left){
                BST_insert(node->left, inserted_node, cnt_smaller);
            }else{
                node->left = inserted_node;
            }
        }else{
            cnt_smaller += node->count + 1;
            if(node->right){
                BST_insert(node->right, inserted_node, cnt_smaller);
            }else{
                node->right = inserted_node;
            }

        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result; // final result
        vector<BSTNode*> node_vec;
        vector<int> count; // from end to beginning inserting, 
                           // how many nodes are smaller than current node
        for(int i = nums.size()-1; i >= 0; i--){
            node_vec.push_back(new BSTNode(nums[i]));
        }
        
        count.push_back(0); 
        for(int i = 1; i < node_vec.size(); i++){
            int cnt_smaller = 0;
            BST_insert(node_vec[0], node_vec[i], cnt_smaller);
            count.push_back(cnt_smaller);
        }
        
        for(int i = node_vec.size()-1; i >= 0; i--){
            delete node_vec[i];
            result.push_back(count[i]);
        }
        return result;
    }
};
