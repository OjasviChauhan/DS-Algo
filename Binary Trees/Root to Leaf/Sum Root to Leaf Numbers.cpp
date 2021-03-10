// https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    long convert(vector<long> &v){
        long res = 0;
        long k = 1;
        for(long i=v.size()-1; i>=0; i--){
            res += v[i]*k;
            k *= 10;
        }
        return res;
    }
    
    void solve(TreeNode* root, vector<long> &v,long &ans){
        if(!root) return;
        if(root->left == NULL and root->right == NULL){
            v.push_back(root->val);
            ans += convert(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        solve(root->left,v,ans);
        solve(root->right,v,ans);
        v.pop_back();
    }
    
    long sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<long> v;
        long ans = 0;
        solve(root,v,ans);
        return ans;
    }
};
