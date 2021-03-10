// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);
        stack<TreeNode*> s;
        s.push(root);
        
        for (int i = 1; i < pre.size(); i++) {
            TreeNode* temp = new TreeNode(pre[i]);
            if (temp->val < s.top()->val)
                s.top()->left = temp;
            else {
                TreeNode* prev;
                while (!s.empty() && s.top()->val < temp->val) {
                    prev = s.top();
                    s.pop();
                }
                prev->right = temp;
            }
            s.push(temp);
        }
        return root;
    }
};
