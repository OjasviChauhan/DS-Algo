// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include<bits/stdc++.h>
using namespace std;
#define int long long

class Graph{
  unordered_map<int,list<int>> l;
  public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void dfs_helper(int src,map<int,bool> &visited,int &count){
        visited[src] = true;
        for(auto nbr:l[src]){
            if(!visited[nbr]){
                count++;
                dfs_helper(nbr,visited,count);
            }
        }
    }
    
    int dfs(int n){
        map<int,bool> visited;
        for(auto p:l){
            int node = p.first;
            visited[node] = false;
        }
        
        int ans = n*(n-1)/2;
        for(auto p:l){
            int count=1;
            int node = p.first;
            if(!visited[node]){
                dfs_helper(node,visited,count);
                int d = count*(count-1)/2;
                ans -= d;
            }  
        }
        return ans;
    }
};

int32_t main(){
    int n,p;
    cin>>n>>p;
    Graph g;
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    cout<<g.dfs(n);
    return 0;
}
