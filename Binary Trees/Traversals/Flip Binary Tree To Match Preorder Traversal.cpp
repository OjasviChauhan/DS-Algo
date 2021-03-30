// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

class Solution {
public:
    vector<int> flips;
    bool dfs(TreeNode* root, vector<int>& voyage, int &pos) {
        if (root == NULL) 
            return true;
        if (root->val != voyage[pos++]) 
            return false;
        
        auto l = root->left; 
        auto r = root->right;
        
        if (l != NULL && l->val != voyage[pos]) {
            flips.push_back(root->val);
            swap(l, r);
        }
        return dfs(l, voyage, pos) && dfs(r, voyage, pos);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage, int pos = 0) {
        return dfs(root, voyage, pos) ? flips : vector<int>() = { -1 };
    }
};
