// Complexity: O(n^2)

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
    int i=0;
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int s, int e){
        if(s>e) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        int index = -1;
        for(int j=s;j<=e;j++){
            if(inorder[j]==preorder[i]){
                index = j;
                break;
            }
        }
        i++;
        root->left = solve(preorder,inorder,s,index-1);
        root->right = solve(preorder,inorder,index+1,e);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};
