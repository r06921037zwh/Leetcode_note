/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* p = root;
        while(p){
            Node* next_level = nullptr;    // the first node of the same level
            Node* prev = nullptr;          // previous node on the same level
            for(; p; p = p->next){
                // determine the begining of the next level
                if(!next_level){
                    if(p->left) next_level = p->left;
                    else if(p->right) next_level = p->right;
                }
                
                if(p->left){
                    if(prev) prev->next = p->left;
                    prev = p->left;
                }
                if(p->right){
                    if(prev) prev->next = p->right;
                    prev = p->right;
                }
            }
            p = next_level; // turn to the next level
        }
        return root;
    }
};
