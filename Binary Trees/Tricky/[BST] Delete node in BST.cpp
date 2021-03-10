/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(key == root->val){
            // Case 1: No children
            if(root->left == NULL and root->right == NULL){
                delete root;
                return NULL;
            }
            
            // Case 2a: Only 1 child on left
            else if(root->left!=NULL and root->right==NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 2b: Only 1 child on right
            else if(root->left==NULL and root->right!=NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            
            // Case 3: both children are present
            else{
                // traverse till the leftmost node of right subtree
                // or till the minimum node of left subtree
                TreeNode* temp = root->right;
                while(temp->left!=NULL){
                    temp = temp->left;                
                }
                
                // replace the root value with leftmost node's value
                root->val = temp->val;
                
                // delete the leftmost node by again calling recursive 
                // function which will run for either of the first two cases.
                root->right = deleteNode(root->right,temp->val);
            }
        }
        else if(key<root->val)
            root->left = deleteNode(root->left,key);
        
        else if(key>root->val)
            root->right = deleteNode(root->right,key);
        
        return root;
    }
};
