// https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode* mn = NULL;
        stack<TreeNode*> s;
        
        while(root or !s.empty()) {
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top(); 
            s.pop();
            if(mn != NULL and root->val <= mn->val) return false;
            mn = root;
            root = root->right;
        }
        return true;
    }
};

// SOLUTION 2
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
