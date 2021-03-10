// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root,priority_queue<int> &pq,int k){
    if(pq.size()>k) pq.pop();
    if(!root) return;
    inorder(root->left,pq,k);
    pq.push(root->val);
    inorder(root->right,pq,k);
} 

int Solution::kthsmallest(TreeNode* A, int B) {
    priority_queue<int> pq;
    inorder(A,pq,B);
    return pq.top();
}
