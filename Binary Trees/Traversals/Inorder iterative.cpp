class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* t = root;
        while(t or !s.empty()){
            while(t){
                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            ans.push_back(t->val);
            t = t->right;
        }
        return ans;
    }
};
