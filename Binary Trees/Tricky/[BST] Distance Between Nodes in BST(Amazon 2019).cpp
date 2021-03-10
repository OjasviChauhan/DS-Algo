// https://leetcode.com/discuss/interview-question/376375/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int v){
            val = v;
            left = NULL;
            right = NULL;
        }
};

TreeNode* buildBST(int A[],int s,int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;

    TreeNode* root = new TreeNode(A[mid]);
    root->left = buildBST(A,s,mid-1);
    root->right = buildBST(A,mid+1,e);
    return root;
}

TreeNode* lca(TreeNode* root,int a,int b){
    if(!root) return NULL;
    if(root->val == a || root->val == b){
        return root;
    }
    TreeNode* leftAns = lca(root->left,a,b);
    TreeNode* rightAns = lca(root->right,a,b);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    if(leftAns!=NULL){
        return leftAns;
    }
    return rightAns;
}

int calculateLevel(TreeNode* root,int key,int level){
    if(!root) return -1;
    if(root->val == key) return level;
    
    int left = calculateLevel(root->left,key,level+1);
    if(left != -1){
        return left;
    }
    return calculateLevel(root->right,key,level+1);
}

int distance(TreeNode* root,int a,int b){
    if(!root) return 0;
    int l1 = calculateLevel(root,a,0);
    int l2 = calculateLevel(root,b,0);
    return l1+l2;
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A,A+n);
    int a,b;
    cin>>a>>b;
    TreeNode* root = buildBST(A,0,n-1);
    TreeNode* lcaNode = lca(root,a,b);
    cout<< distance(lcaNode,a,b)<<endl;
    return 0;
}
