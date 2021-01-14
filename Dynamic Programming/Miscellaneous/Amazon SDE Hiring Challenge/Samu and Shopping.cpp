// https://assessment.hackerearth.com/challenges/hiring/amazon-sde-hiring-challenge-2/algorithm/samu-and-shopping-165-5691d19b/

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

int solve(int A[][3],int n){
	int dp[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			if(i==0){
				dp[i][j] = A[i][j];
			}
			else{
				if(j==0){
					dp[i][j] = A[i][j] + min(dp[i-1][1],dp[i-1][2]);
				}
				else if(j==1){
					dp[i][j] = A[i][j] + min(dp[i-1][0],dp[i-1][2]);
				}
				else{
					dp[i][j] = A[i][j] + min(dp[i-1][0],dp[i-1][1]);
				}
			}
		}
	}
	return min(dp[n-1][0], min(dp[n-1][1],dp[n-1][2]));
}

int32_t main(){
	fast;

	int t;
	cin>>t;
	while(t--)
    {
		int n;
		cin>>n;
		int A[n][3];

		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>A[i][j];
			}
		}
		cout<<solve(A,n)<<endl;
	}
}
