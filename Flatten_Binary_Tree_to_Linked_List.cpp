/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /* Solution 1
 Simple travesal and make list
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> results;
        traversal(root, results);
        for(int i=1; i<results.size(); i++){
            results[i-1]->right = results[i];
            results[i-1]->left = NULL;
        }
    }
    void traversal(TreeNode* node, vector<TreeNode*>& results){
        if(!node){
            return;
        }
        results.push_back(node);
        traversal(node->left, results);
        traversal(node->right, results);
    }
};

 /* Solution 2
 With Stack Iterative Method
 */
 
 #include <stack>
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return ;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* p = s.top();
            s.pop();
            
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
            
            if(!s.empty()) p->right = s.top();
            p->left = NULL;
        }
    }
};
