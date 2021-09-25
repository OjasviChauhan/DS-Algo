// https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int sz = q.size();
            int first, last;
            int min_idx = q.front().second;
            
            for(int i = 0; i < sz; i++) {
                auto t = q.front();
                q.pop();
                
                TreeNode* node = t.first;
                int idx = t.second - min_idx; // to avoid overflow, subtract
                // minimum index of parent level, from current idx which you have
                // to assign on coming children nodes. 
                
                if(i == 0) first = idx;
                if(i == sz-1) last = idx;
                
                if(node->left) {
                    q.push({node->left, 2*idx + 1});
                }
                if(node->right) {
                    q.push({node->right, 2*idx + 2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
