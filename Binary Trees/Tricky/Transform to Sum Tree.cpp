int solve(Node* root){
    if(root==NULL){
        return 0;
    }

    int temp = root->data;
    root->data = solve(root->left) + solve(root->right);
    return temp + root->data;
}

void toSumTree(Node* root)
{
    solve(root);
}
