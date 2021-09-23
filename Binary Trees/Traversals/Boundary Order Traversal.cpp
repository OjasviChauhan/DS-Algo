// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

class Solution {
public:
    bool isLeaf(Node* root){
        if(!root->left and !root->right)
            return true;
        return false;
    }

    void addLeft(Node* root, vector<int> &ds) {
        Node* cur = root->left;
        while(cur) {
            if(!isLeaf(cur)) ds.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addLeaves(Node* root, vector<int> &ds) {
        if(!root) return;
        if(isLeaf(root)){
            ds.push_back(root->data);
            return;
        }
        addLeaves(root->left, ds);
        addLeaves(root->right, ds);
    }

    void addRight(Node* root, vector<int> &ds) {
        Node* cur = root->right;
        vector<int> temp;
        while(cur) {
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for(int i = temp.size()-1; i >= 0; i--){
            ds.push_back(temp[i]);
        }
    }

    vector <int> printBoundary(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
      
        addLeft(root, ans);
        addLeaves(root, ans);
        addRight(root, ans);
        
        return ans;
    }
};
