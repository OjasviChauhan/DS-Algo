#include <bits/stdc++.h>
using namespace std;

class Graph{
	unordered_map<int,list<int>> l;
public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(int src,int V,int &ans){
		map<int,int> dist;
		queue<int> q;
		for(int i=1;i<=V;i++){
			dist[i] = INT_MAX; 
		}
		
		dist[src]=0;
		q.push(src);

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(int nbr : l[node]){
				if(dist[nbr]==INT_MAX){
					// nbr is not visited
					dist[nbr] = dist[node] + 1;
					q.push(nbr);
				}
				else if(dist[nbr]>=dist[node]){
					// nbr is visited as well as its not the parent 
					ans = min(ans, dist[nbr]+dist[node]+1);
				}
			}
		}
	}

};

int main(){
	int V,E;
	cin>>V>>E;
	
	Graph g;

	for(int i=0;i<E;i++){
		int a,b;
		cin>>a>>b;
		g.addEdge(a,b);
	}

    int ans = V+1;
    // we have to run bfs call on every node to make sure 
    // that we are checking all cases for shortest cycle
	for(int i=1;i<=V;i++){
	    g.bfs(i,V,ans);
	}
    
    if(ans==V+1) cout<<"Cycle isn't present"<<endl;
    else cout<<"Shortest Cycle is of length: "<<ans<<endl;
    
	return 0;
}