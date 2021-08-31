// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#define ll long long
#define pll pair<ll, ll>

class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> g(n);
        
        for(vector<int> &x : roads) {
            ll u = x[0], v = x[1], wt = x[2];
            g[u].push_back({v, wt});
            g[v].push_back({u, wt});
        }
        
        vector<ll> dist(n, LONG_MAX);
        vector<ll> paths(n);
        
        dist[0] = 0;
        paths[0] = 1;
        
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0,0});  // dist, src
        
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            
            for(auto nbr : g[u]){
                ll v = nbr.first;
                ll wt = nbr.second;
                
                if(d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                    paths[v] = paths[u];
                }
                else if(d + wt == dist[v]){
                    paths[v] = (paths[v] + paths[u]) % MOD;
                }
            }
        }
        return paths[n-1];
    }
};
