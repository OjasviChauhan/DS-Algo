// https://leetcode.com/problems/path-sum-ii/submissions/

class Solution {
public:
    void solve(TreeNode* root, int k,int temp,vector<int> &ds, vector<vector<int>> &ans){
        if(!root) return;
        if(!root->left and !root->right){
            temp += root->val;
            if(temp == k){
                ds.push_back(root->val);
                ans.push_back(ds);
                ds.pop_back();
                return;
            }
            return;
        }
        temp += root->val;
        ds.push_back(root->val);
        solve(root->left,k,temp,ds,ans);
        solve(root->right,k,temp,ds,ans);
        ds.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(root,k,0,ds,ans);
        return ans;
    }
};
