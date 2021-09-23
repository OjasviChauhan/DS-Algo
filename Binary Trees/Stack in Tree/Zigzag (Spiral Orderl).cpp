// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Solution 1

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> ds(size);
            
            for(int i = 0; i < size; i++){
                auto t = q.front();
                q.pop();
                
                int idx = leftToRight ? i : size-i-1;
                ds[idx] = t->val;
                
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(ds);
        }
        return ans;
    }
};


// Solution 2

class Solution {
public:
    void zigZag(TreeNode* root, vector<vector<int>> &v){
        if(root==NULL){
            return;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        
        while(!s1.empty() || !s2.empty()){
            vector<int> t;
            while(!s1.empty()){
                TreeNode* f = s1.top();
                if(f->left) s2.push(f->left);
                if(f->right) s2.push(f->right);
                s1.pop();
                t.push_back(f->val);
            }
            v.push_back(t);
            t.clear();
            
            while(!s2.empty()){
                TreeNode* f = s2.top();
                if(f->right) s1.push(f->right);
                if(f->left) s1.push(f->left);
                s2.pop();
                t.push_back(f->val);
            }
            if(!t.empty()) v.push_back(t);
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        zigZag(root,v);
        return v;
    }
};
