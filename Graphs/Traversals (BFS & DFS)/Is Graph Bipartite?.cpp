// https://leetcode.com/problems/is-graph-bipartite/submissions/

class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int src,int *visited,int c){
        visited[src] = c;
        for(auto nbr:graph[src]){
            if(visited[nbr]==0){
                if(!dfs(graph,nbr,visited,3-c))
                    return false;
            }
            else if(nbr!=src and visited[nbr]==c){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int *visited = new int[V];
        bool ans = true;
        
        for(int i=0;i<V;i++){
            visited[i]=0;
        }
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                ans = dfs(graph,i,visited,1);
                if(!ans) break;
            }
        }
        
        return ans;
    }
};
