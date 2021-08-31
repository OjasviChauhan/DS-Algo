// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    void find_paths(vector<vector<int>> &paths, vector<int> &path, vector<int> parent[], int u) {
        if (u == -1) {
            paths.push_back(path);
            return;
        }
        for (int par : parent[u]) {
            path.push_back(u);
            find_paths(paths, path, parent, par);
            path.pop_back();
        }
    }

    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n);
        
        for(vector<int> x : roads) {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            g[u].push_back({v, wt});
            g[v].push_back({u, wt});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        
        vector<int> par[n];
        par[0] = {-1};
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            
            for(auto nbr : g[u]){
                int v = nbr.first;
                int wt = nbr.second;
                if(d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                    
                    par[v].clear();
                    par[v].push_back(u);
                }
                else if(d + wt == dist[v]){
                    par[v].push_back(u);
                }
            }
        }
        vector<vector<int>> paths;
        vector<int> path;
        
        find_paths(paths, path, par, n-1);
        
        for(auto v : paths) {
            reverse(v.begin(), v.end());
            for(int u : v){
                cout << u << "->"; 
            }
            cout << endl;
        }
        return paths.size();
    }
};
