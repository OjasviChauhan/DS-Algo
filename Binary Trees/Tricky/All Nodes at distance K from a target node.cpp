// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> par;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {    
        queue<TreeNode*> q;
        
        q.push(root);
        par[root] = NULL;
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            
            if(t->left){
                par[t->left] = t;
                q.push(t->left);
            }
            if(t->right) {
                par[t->right] = t;
                q.push(t->right);
            }
        }
        
        int dist = 0;
        unordered_map<TreeNode*, int> vis;
        queue<TreeNode*> Q;
        Q.push(target);
        vis[target] = 1;
        
        while(!Q.empty()) {
            
            if(dist == k) {
                while(!Q.empty()){
                    ans.push_back(Q.front()->val);
                    Q.pop();
                }
            }

            int sz = Q.size();
            for(int i = 0; i < sz; i++) {
                auto t = Q.front();
                Q.pop();
                
                if(t->left and !vis[t->left]) {
                    Q.push(t->left);
                    vis[t->left] = 1;
                }
                if(t->right and !vis[t->right]) {
                    Q.push(t->right);
                    vis[t->right] = 1;
                }
                if(par[t] and !vis[par[t]]){
                    Q.push(par[t]);
                    vis[par[t]] = 1;
                }
            }
            dist++;
        }
        return ans;
    }
};
