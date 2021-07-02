class Solution {
public:
    bool contains_cycle(int src, vector<vector<int>> &gr, vector<bool> &vis, vector<bool> &stack, vector<int> &ans){
        vis[src] = true;
        stack[src] = true;
        for(auto nbr : gr[src]){
            if(!vis[nbr] and contains_cycle(nbr, gr, vis, stack, ans)){
                return true;
            }
            else if(stack[src]) return true;
        }
        stack[src] = false;
        ans.push_back(src);
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> gr(n);
        for(int i=0; i < pre.size(); i++){
            gr[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> ans;
        vector<bool> vis(n, false);
        vector<bool> stack(n, false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                bool cycle_mila = contains_cycle(i, gr, vis, stack, ans);
                if(cycle_mila) {
                    return {};
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
