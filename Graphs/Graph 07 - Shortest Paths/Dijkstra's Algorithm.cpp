#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define int long long
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
int mod=1000000007;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> l;
public:
    void addEdge(int x,int y,int dist,bool bidir=true){
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
        dist[src] = 0;   // except source
        
        // making a set to store the data(distance,name) of nodes.
        set<pair<int,T>> s;
        s.insert({0,src});

        while(!s.empty()){
            // find the node at the minimum distance from src which 
            // will be at the front of the set.
            auto p = *s.begin();
            int nodeDist = p.first;
            T node = p.second;

            s.erase(s.begin());
            
            // Iterate over the neighbours of the current node
            for(auto nbr:l[node]){
                if(nodeDist + nbr.second < dist[nbr.first]){
                    // for updation, we have to erase the old data of destination node
                    // from the set and insert the new data for that node.
                    
                    T dest = nbr.first;     // the destination node on which we are going
                    auto f = s.find({dist[dest], dest});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    
                    // Insert the new data
                    dist[dest] = nodeDist + nbr.second;
                    s.insert({dist[dest], dest});
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
