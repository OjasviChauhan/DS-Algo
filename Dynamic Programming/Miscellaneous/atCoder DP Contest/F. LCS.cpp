// https://atcoder.jp/contests/dp/tasks/dp_f

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

string LCS(string s,string t){
	int n = s.size();
	int m = t.size();

	int dp[n+1][m+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else{
				if(s[i-1]==t[j-1])
					dp[i][j] = 1 + dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string ans="";
	int i=n,j=m;
	while(i>0 and j>0){
		if(s[i-1]==t[j-1]){
			ans += s[i-1];
			i--; j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else j--;
	}

	reverse(ans.begin(),ans.end());
	return ans;
}

int32_t main(){
	fast;
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

	string s,t;
	cin>>s>>t;
	cout<<LCS(s,t)<<endl;

	return 0;
}
