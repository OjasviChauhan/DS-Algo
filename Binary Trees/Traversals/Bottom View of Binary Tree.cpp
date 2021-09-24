// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0 ; i < sz; i++) {
                auto t = q.front();
                q.pop();
                
                Node* n = t.first;
                int x = t.second; 
                
                mp[x] = n->data;
                
                if(n->left) {
                    q.push({n->left, x-1});
                }
                if(n->right) {
                    q.push({n->right, x+1});
                }
            }
        }
    
        for(auto p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
