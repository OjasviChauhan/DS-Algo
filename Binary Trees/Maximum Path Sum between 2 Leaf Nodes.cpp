/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
int solve(Node* root,int &res){
    if(!root) return 0;
    
    // check if its a leaf node, then return data of leaf node
    if(!root->left and !root->right) {
        return root->data;
    }
    
    // find maximum root to leaf sums in left and right 
    // subtrees and store them in ls and rs
    int ls = solve(root->left,res);
    int rs = solve(root->right,res);
    
    
    // If both left and right children exist 
    if(root->left and root->right){
        // update the result if required
        res = max(res, ls+rs+root->data);
        return max(ls,rs) + root->data;    
    }
    
    // Otherwise return whoever is present
    return(!root->left) ? rs+root->data : ls+root->data;
}


int maxPathSum(Node* root)
{ 
   int res = INT_MIN; 
   solve(root,res);
   return res;
}
