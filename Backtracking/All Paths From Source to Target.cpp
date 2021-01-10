// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<vector<int>>& graph,vector<int> &v,int src,int last){
        v.push_back(src);
        if(src==last){
            ans.push_back(v);
            return;
        }
        for(auto nbr:graph[src]){
            solve(graph,v,nbr,last);
            v.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v;
        solve(graph,v,0,n-1);
        return ans;
    }
};
