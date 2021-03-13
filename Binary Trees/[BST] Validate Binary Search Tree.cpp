// https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
     bool isValidBST(TreeNode* root, TreeNode* min=NULL, TreeNode* max=NULL) {
        if (!root) 
            return true;
        if (min != NULL and root->val <= min->val) 
            return false;
        if (max != NULL and root->val >= max->val) 
            return false;
        return isValidBST(root->left, min, root) and isValidBST(root->right, root, max);
    }
};
