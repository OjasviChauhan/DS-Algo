bool ans;
int height(Node* root){
    if(root==NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
        
    if(abs(lh - rh) > 1) ans = false;
        
    return max(lh, rh) + 1;
}

bool isBalanced(Node *root)
{
    if(root==NULL) return true;
    ans = true;
    height(root);
    return ans;
}
