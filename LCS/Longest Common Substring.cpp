#include <bits/stdc++.h>
using namespace std;
 
int LCSubstring(string x,string y,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;			// Code Variation.
            }
        }
    }
    int Max = 0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(dp[i][j] > Max){
                Max = dp[i][j];			// Code Variation.
            }
        }
    }
    return Max;
}

int32_t main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    while(t-- > 0)
    {
        int n,m;
        cin>>m>>n;
        string x,y;
        cin>>x>>y;
        int ans = LCSubstring(x,y,m,n);
        cout<<ans<<endl;
    }
	return 0;
}
