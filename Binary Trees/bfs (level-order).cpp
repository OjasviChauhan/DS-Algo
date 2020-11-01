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
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        node* d = q.front();
        cout<<d->data<<" ";
        
        if(d->left){
            q.push(d->left);
        }
        if(d->right){
            q.push(d->right);
        }
        q.pop();
    }
}

int main() {
    node* root = buildTree();
    cout<<"Level Order: ";
    bfs(root);
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
