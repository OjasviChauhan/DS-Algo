//https://leetcode.com/problems/invert-binary-tree/

// Recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* r = invertTree(root->right);
        TreeNode* l = invertTree(root->left);
        root->left = r;
        root->right = l;
        return root;
    }
};

// Iterative
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); 
            q.pop();
            swap(node->left, node->right);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        } 
        return root;
    }
};
