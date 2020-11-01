#include <bits/stdc++.h>
using namespace std;

class node{
    public:      
        int data;
        node* left;
        node* right;
          
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;
    
    if(d==-1){
        return NULL;
    }
    
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void bfs(node* root){
    if (root == NULL) 
        return;

    stack<node*> s1;
    stack<node*> s2;

    s1.push(root);

    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node* d = s1.top();
            cout<<d->data<<" ";
            s1.pop();

            if(d->left)
                s2.push(d->left);
            if(d->right)
                s2.push(d->right);
        }
        while(!s2.empty()){
            node* d = s2.top();
            cout<<d->data<<" ";
            s2.pop();

            if(d->right)
                s1.push(d->right);
            if(d->left)
                s1.push(d->left);
        }
    }
}

int main(){
    node* root = buildTree();
    bfs(root);
    return 0;
}
