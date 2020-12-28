// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
    int findHeight(TreeNode* root){
        if(!root) return 0;
        return 1+max(findHeight(root->left), findHeight(root->right));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        
        if(left==right) 
            return root;
        else if(left>right) 
            return lcaDeepestLeaves(root->left);
        
        return lcaDeepestLeaves(root->right);
    }
};
