// https://leetcode.com/problems/path-sum/

class Solution {
public:
    bool solve(TreeNode* root,int k,int temp){
        if(!root) return false;
        if(!root->left and !root->right){
            temp += root->val; 
            return temp == k;
        }
        temp += root->val;
        if(solve(root->left,k,temp))
            return true;
        if(solve(root->right,k,temp))
            return true;
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int k) {
        if(!root) return false;
        return solve(root,k,0);
    }
};
