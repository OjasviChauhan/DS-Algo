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

class Pair{
    public:
        int height;
        int diameter;
};

Pair diameterOpt(node* root){
    Pair Node;
    if(root==NULL){
        Node.height = 0; 
        Node.diameter = 0;
        return Node;
    }

    Pair leftSubTree = diameterOpt(root->left);
    Pair rightSubTree = diameterOpt(root->right);

    Node.height = max(leftSubTree.height, rightSubTree.height) + 1;
    Node.diameter = max(leftSubTree.height + rightSubTree.height + 1, 
                    max(leftSubTree.diameter, rightSubTree.diameter));

    return Node;
}

int main(){
    node* root = buildTree();
    Pair p = diameterOpt(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;
    return 0;
}

/*
Input:  8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Output: 
4
7
*/
