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
        for(auto p:l){
            dist[p.first] = INT_MAX;
        }
        dist[src] = 0;

        set<pair<int,T>> s;
        s.insert({0,src});

        while(!s.empty()){
            auto p = *s.begin();
            int nodeDist = p.first;
            T node = p.second;

            s.erase(s.begin());
            
            for(auto nbr:l[node]){
                if(nodeDist + nbr.second < dist[nbr.first]){
                    T dest = nbr.first; // the destination node on which we are going
                    auto f = s.find({dist[dest], dest});
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    dist[dest] = nodeDist + nbr.second;
                    s.insert({dist[dest], dest});
                }
            }
        }

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
