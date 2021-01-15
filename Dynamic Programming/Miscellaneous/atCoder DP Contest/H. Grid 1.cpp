// https://atcoder.jp/contests/dp/tasks/dp_h

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

char grid[1001][1001];

int solve(int n,int m){
	int dp[n][m];
	memset(dp,0,sizeof dp);

	for(int i=0;i<n;i++){
		if(grid[i][0]=='#')
			break;
		dp[i][0] = 1;
	}
	for(int j=0;j<n;j++){
		if(grid[0][j]=='#')
			break;
		dp[0][j] = 1;
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(grid[i][j] == '#'){
				dp[i][j]=0;
			}
			else{
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
			}
		}
	}

	return dp[n-1][m-1];
}

int32_t main(){
	fast;
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> grid[i][j];
    	}
    }

    cout<<solve(n,m);

	return 0;
}
