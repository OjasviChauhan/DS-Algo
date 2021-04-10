// https://leetcode.com/problems/path-sum-iii/

class Solution {
public:
    int cnt = 0;
    
    void solve(TreeNode* root, int sum){
        if(!root) return;
        if(root->val == sum) cnt++;
        solve(root->left, sum - root->val);
        solve(root->right, sum - root->val);
        return;
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        solve(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return cnt;
    }
};
