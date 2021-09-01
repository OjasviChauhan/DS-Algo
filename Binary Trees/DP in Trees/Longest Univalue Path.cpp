// https://leetcode.com/problems/longest-univalue-path/

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
    
    int solve(TreeNode *root, int& ans){
        if(!root) return 0;
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        
        l = (root->left and root->left->val == root->val) ? l + 1 : 0;
        r = (root->right and root->right->val == root->val) ? r + 1 : 0;
        
        ans = max(ans, l + r);
        return max(l, r);
    }
};
