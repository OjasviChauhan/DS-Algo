bool ans;
int height(Node* root){
    if(root==NULL) return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
        
    if(abs(lHeight - rHeight) > 1) ans = false;
        
    return max(lHeight,rHeight) + 1;
}

bool isBalanced(Node *root)
{
    if(root==NULL) return true;
    ans = true;
    height(root);
    return ans;
}
