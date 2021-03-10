// The diameter of a tree (sometimes called the width) is the number of nodes on 
// the longest path between two end nodes.

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int hl = height(root->left);      // height of left sub tree
    int hr = height(root->right);     // height of rigth sub tree

    // Return max of the following tree: 
    // 1) Diameter of left subtree 
    // 2) Diameter of right subtree 
    // 3) Height of left subtree + height of right subtree + 1 
    return max(hl+hr+1, max(diameter(root->left), diameter(root->right)));
}

int main(){
    node* root = buildTree();
    cout<<diameter(root)<<endl;
    return 0;
}

/*
Input:  8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Output: 7
*/
