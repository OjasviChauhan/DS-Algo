// https://codeforces.com/problemset/problem/1093/D

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
int mod1=998244353;


vector<vector<int>> gr;
int n,m;
int cnt0=0, cnt1=0, flag = 1;

int pow1(int a,int b){
    a%=mod1;
    int res=1;
    while (b>0){
        if (b & 1)
        res=res*a%mod1;
        a=a*a%mod1;
        b>>=1;
    }
    return res;
}

void dfs(int i, vector<int> &visited,int parity = 0){
	if(visited[i]){
		// parity would be either 0 or 1
		if(1 + parity != visited[i])
			flag = 0;
		return;
	}

	if(parity == 0){
		cnt0++;      
		visited[i] = 1;  // 1 is representing odd  
	}
	else{
		cnt1++;
		visited[i] = 2;  // 2 is representing even
	}

	for(auto nbr:gr[i])
		dfs(nbr,visited,1-parity);	
}

int solve(){
	int ans=1;
	vector<int> visited(n+1,0);

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			// cnt0 is for odd and cnt1 is for even
			// flag denotes graph is beautiful or not
			cnt0=0, cnt1=0, flag = 1;
			
			dfs(i,visited);

			if(!flag)
				return 0;

			ans = (ans * (pow1(2,cnt0) + pow1(2,cnt1))) % mod1;

		}
	}
	return ans;
}

int32_t main(){
	fast;

    int t;
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	gr.clear();
    	gr.resize(n+1);

    	for(int i=0;i<m;i++){
    		int u,v;
    		cin>>u>>v;
    		gr[u].push_back(v);
    		gr[v].push_back(u);
    	}

    	cout<<solve()<<endl;
    }

	return 0;
}
