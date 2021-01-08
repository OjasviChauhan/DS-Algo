#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> l;
public:
    void addEdge(T x,T y,int dist,bool bidir=true){
        l[x].push_back({y,dist});
        if(bidir)
            l[y].push_back({x,dist});
    }

    void dijkstra(T src){
        unordered_map<T,int> dist;
        
        // Initialize all distances at infinity.
        for(auto p:l){
            dist[p.first] = INT_MAX;
        }
        dist[src] = 0;   
        
        // making a set to store the data(distance,name) of nodes.
        set<pair<int,T>> s;
        s.insert({0,src});

        while(!s.empty()){
            // find the pair at the front
            auto p = *s.begin();
            s.erase(s.begin());
            
            T node = p.second;
            
            // Iterate over the neighbours of the current node
            for(auto nbrs:l[node]){
                T nbr = nbrs.first;
                int wt = nbrs.second;

                if(dist[node] + wt < dist[nbr]){
                    auto f = s.find({dist[nbr], nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    
                    dist[nbr] = dist[node] + wt;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        
        // printing all distances
        for(auto d:dist){
            cout<<d.first<<" is located at distance: "<<d.second<<endl;
        }
    }

};


int32_t main(){

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);

    g.dijkstra(1);

    return 0;
}
