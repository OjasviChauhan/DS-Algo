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
    int sum(TreeNode* root, int &ans) {
        if(!root) return 0;
        
        // we will not consider -ve sum coming back from left or right
        // sub tree, because that will always lead to smaller path sum.
        int ls = max(0, sum(root->left, ans));
        int rs = max(0, sum(root->right, ans));
        
        // update ans if umbrella shaped path is larger than current ans
        ans = max(ans, root->val + ls + rs);
        
        // return maximum of both the sums to ensure the maximum path for 
        // upper nodes so that always maximum path could be taken.
        return root->val + max(ls, rs);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        sum(root, ans);
        return ans;
    }
};
