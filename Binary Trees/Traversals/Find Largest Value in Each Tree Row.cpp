// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);
        
        while(!q.empty()){
            int n = q.size();
            int maxLevel = INT_MIN;
            
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                    maxLevel = max(maxLevel, q.back()->val);
                }
                if(node->right) {
                    q.push(node->right);
                    maxLevel = max(maxLevel, q.back()->val);
                }
            }
            ans.push_back(maxLevel);
        }
        ans.pop_back();
        return ans;
    }
};
