// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    unordered_map<int,int> mp;
    int i;
    
    void init(int n){
        i = n-1;
    }
    
    TreeNode* solve(vector<int>& post, int s,int e){
        if(s > e) return NULL;
        TreeNode* root = new TreeNode(post[i]);
        int index = mp[post[i--]];
        root->right = solve(post,index+1,e);
        root->left = solve(post,s,index-1);
        return root;   
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0; i < in.size(); i++){
            mp[in[i]] = i;
        }
        init(post.size());
        return solve(post,0,in.size()-1);
    }
};
