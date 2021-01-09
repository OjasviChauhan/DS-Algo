#include<bits/stdc++.h>
using namespace std;

class DSU{
	int *par;
	int *rank;
public:
	DSU(int v){
		par = new int[v];
		rank = new int[v];

		for(int i=0;i<v;i++){
			par[i] = -1;
			rank[i] = 1;
		}
	}

	int get(int i){
		return par[i]==-1 ? i : par[i]=get(par[i]);
	}

	void unite(int x,int y){
		int s1 = get(x);
		int s2 = get(y);
		if(s1!=s2){
			if(rank[s2]>rank[s1]){
				par[s1] = s2;
				rank[s2] += rank[s1];
			}
			else{
				par[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

int kruksal(vector<vector<int>> &l,int v){
	DSU g(v);

	int ans=0;
	sort(l.begin(),l.end());

	for(auto p:l){
		int wt = p[0];
		int x = p[1];
		int y = p[2];

		if(g.get(x) != g.get(y)){
			g.unite(x,y);
			ans += wt;
		}
	}
	return ans;
}

int main(){

	int v,e;
	cin>>v>>e;

	vector<vector<int>> l;

	while(e--){
		int x,y,w;
		cin>>x>>y>>w;
		l.push_back({w,x,y});
		l.push_back({w,x,y});
	}

	cout<<kruksal(l,v);
	return 0;
}