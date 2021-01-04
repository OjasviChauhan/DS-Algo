#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl;

class Graph{
	unordered_map<int,list<pair<int,int>>> l;
public:
	void addEdge(int x,int y,int wt){
		l[x].push_back({y,wt});
		l[y].push_back({x,wt});
	}

	int dfsHelper(int src,bool *visited,int *count, int &ans,int V){
		visited[src] = true; 
		for(auto nbr:l[src]){
			int node = nbr.ff;
			int wt = nbr.ss;
			if(!visited[node]){
				count[src] += dfsHelper(node,visited,count,ans,V);
                int nx = count[node];
                int ny = V - nx;
				ans += 2*min(nx,ny)*wt;
			}
		}
		return count[src];
	}

	int dfs(int n){
		bool *visited = new bool[n+1];
		int *count = new int[n+1];
		for(int i=0;i<=n;i++){
			visited[i] = false;
			count[i] = 1;
		}

        int ans=0;
		dfsHelper(1,visited,count,ans,n);
		return ans;
	}
};

int solve()
{
	int n;
	cin>>n;
	
	Graph g;
	for(int i=1;i<=n-1;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g.addEdge(x,y,z);
	}
	return g.dfs(n);
}

int32_t main(){
	fast;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
       cout<<"Case #"<<i<<": "<<solve()<<endl; 
    }
	
	return 0;
}
