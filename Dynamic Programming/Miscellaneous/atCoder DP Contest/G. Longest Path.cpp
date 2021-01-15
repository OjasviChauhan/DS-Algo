// https://atcoder.jp/contests/dp/tasks/dp_g

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

vector<int> graph[100001];
int dp[100001];

int longestPath(int src){
	if(dp[src] != -1)
		return dp[src];

	bool leaf = true;
	int bestNbr = 0;
	for(int nbr:graph[src]){
		leaf = false;
		bestNbr = max(bestNbr, longestPath(nbr));
	}
	
	return dp[src] = leaf ? 0 : 1+bestNbr;
}

int32_t main(){
	fast;
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
	memset(dp,-1,sizeof dp);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}

	int ans=0;
	for(int i=1;i<=n;i++){
		ans = max(ans, longestPath(i));
	}
	cout<<ans<<endl;

	return 0;
}
