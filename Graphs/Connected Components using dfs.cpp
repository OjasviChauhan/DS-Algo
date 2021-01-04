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
    
    void dfs_helper(T src, map<T,bool> &visited){
        // Recursive function that will traverse the graph
        cout<<src<<" ";
        visited[src] = true;
        
        // go to all nbrs of that node that is not visited
        for(auto nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);   
            }
        }
    }
    
    void dfs(){
        map<T,bool> visited;
        // Mark all nodes as not visited in the begining
        for(auto p:l){
            T node = p.first;
            visited[node] = false;
        }

        int count=1;
        for(auto p:l){
        	T node = p.first;
        	if(!visited[node]){
        		cout<<"Component "<<count<<" --> ";
        		dfs_helper(node,visited);
        		count++;
        		cout<<endl;
        	}
        }
        
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(0,4);

    g.addEdge(6,5);
    g.addEdge(6,7);
    
    g.addEdge(8,8);

    g.dfs();
    
    return 0;
}
