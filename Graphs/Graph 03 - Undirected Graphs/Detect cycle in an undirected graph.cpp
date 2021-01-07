// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> *l, bool* visited, int src,int parent){
    visited[src]=true;
    for(auto nbr:l[src]){
        if(!visited[nbr]){
            if(dfs(l,visited,nbr,src))
                return true;
        }
        else if(nbr!=parent){
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> l[], int V){
    bool* visited = new bool[V];
    for(int i=0;i<V;i++) visited[i] = false;
	bool ans = false;
	
	for(int i=0;i<V;i++){
	    if(!visited[i]){
	        ans = dfs(l,visited,i,-1);
	        if(ans) break;
	    }
	}
	return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++){
            cin>>u>>v;
         
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;
    }
}
