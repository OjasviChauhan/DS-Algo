// https://leetcode.com/problems/house-robber-iii/

/*
Here we have two choices:

1) Either rob current root and call rob for its grand children

2) Or don't rob current root and just call rob for its children.

*/

class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if(!root) return 0;
        
        if(dp.find(root) != dp.end())
            return dp[root];
        
        int grandChildrenRobValue = 0;
        if(root->left) 
            grandChildrenRobValue += rob(root->left->left) + rob(root->left->right);
        if(root->right) 
            grandChildrenRobValue += rob(root->right->left) + rob(root->right->right);
        
        return dp[root] = max(root->val + grandChildrenRobValue, 
                              rob(root->left) + rob(root->right));
    }
};
