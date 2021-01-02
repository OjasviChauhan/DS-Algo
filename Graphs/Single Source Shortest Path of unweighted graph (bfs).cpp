#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<T>> l;
public:
    void addEdge(T x,T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void bfs(T src){
        unordered_map<T,int> dist;
        queue<T> q;
        
        // initializing all nodes at infinity distance from src
        for(auto p:l){
        	T node = p.first;
        	dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;  // but src dist would be 0
        
        while(!q.empty()){
            T node = q.front();
            q.pop();
            
            for(auto nbr:l[node]){
            	// if you are visiting that node at first time
                if(dist[nbr] == INT_MAX){     
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;  
                }
            }
        }

        // printing the dist to every node
        for(auto p:l){
        	T node = p.first;
        	int d = dist[node];
        	cout<<node<<" is "<<d<<" distance from source"<<endl;
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,5);
    
    g.bfs(0);
    
    return 0;
}
