// https://assessment.hackerearth.com/challenges/hiring/amazon-sde-hiring-challenge-2/algorithm/moving-to-new-office-dd532d09/

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int dp[1000][1000];
int getResult(vector<int> &v,int l,int r,int x,int y){
	if(r-l == 1)
		return 0;

	if(dp[l][r] != -1)
		return dp[l][r];

	int ans = INT_MAX;
	for(int i=l+1;i<r;i++){
		int val = x*(v[i]-v[l]) + y*(v[r]-v[i]);
		int left = getResult(v,l,i,x,y);
		int right = getResult(v,i,r,x,y);
		ans = min(ans, val+left+right); 
	}
	return dp[l][r] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int x, y, n;
		cin>>x>>y>>n;
		vector<int> v(n, 0);
		memset(dp, -1, sizeof(dp));
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<getResult(v,0,n-1,x,y)<<"\n";
	}
	return 0;
}
