// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#

class Solution {
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* solve(Node* root) {
        if(!root) return root;
        if(root->left){
            Node* left = solve(root->left);
            while(left->right != NULL) {
                left = left->right;
            }
            left->right = root;
            root->left = left;
        }
        if(root->right){
            Node* right = solve(root->right);
            while(right->left != NULL){
                right = right->left;
            }
            right->left = root;
            root->right = right;
        }
        return root;
    }
    
    Node * bToDLL(Node *root) {
        if (root == NULL)
            return root;

        root = solve(root);
        while (root->left != NULL)
            root = root->left;
            
        return (root);
    }
};
