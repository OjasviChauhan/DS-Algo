// https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* n = new TreeNode(v);
            n->left = root;
            return n;
        }
        
        if(!root) return NULL;
        
        if(d == 2){
            TreeNode* t = root->left;
            root->left = new TreeNode(v);
            root->left->left = t; 
                
            t = root->right;
            root->right = new TreeNode(v);
            root->right->right = t;
            
            return root;
        }
        
        addOneRow(root->left,v,d-1);
        addOneRow(root->right,v,d-1);
        return root;
    }
};
