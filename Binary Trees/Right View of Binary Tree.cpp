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
    int maxLevel = -1;
    void solve(TreeNode* root, vector<int> &v,int level){
        if(!root) return;
        if(level > maxLevel){
            v.push_back(root->val);
            maxLevel = level;
        }
        solve(root->right,v,level+1);
        solve(root->left,v,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        solve(root,v,0);
        return v;
    }
};

// SOLUTION 2

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                if(i == sz - 1) 
                    ans.push_back(t->val);
            }
        }
        return ans;
    }
};
