// https://leetcode.com/problems/merge-two-binary-trees/

class Solution {
public: 
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        
        int val1 = t1 ? t1->val : 0;
        int val2 = t2 ? t2->val : 0;
        
        TreeNode* t = new TreeNode(val1 + val2);
        t->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
        t->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
        
        return t;
    }
};
