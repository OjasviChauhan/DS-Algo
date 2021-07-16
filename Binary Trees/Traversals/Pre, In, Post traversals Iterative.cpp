// PRE-ORDER
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ans;
    }
};


// IN-ORDER
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* t = root;
        while(t or !s.empty()){
            while(t){
                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            ans.push_back(t->val);
            t = t->right;
        }
        return ans;
    }
};


// POST-ORDER
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
