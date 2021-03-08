// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
        int i=0;
        unordered_map<int,int> mp;
    public:
        TreeNode* solve(vector<int>& preorder,int s,int e){
            if(s>e) return NULL;
            TreeNode* root = new TreeNode(preorder[i]);
            int index = mp[preorder[i++]];
            root->left = solve(preorder,s,index-1);
            root->right = solve(preorder,index+1,e);
            return root;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            for(int i=0;i<inorder.size();i++){
                mp[inorder[i]] = i;
            }
            return solve(preorder,0,inorder.size()-1);
        }
};
