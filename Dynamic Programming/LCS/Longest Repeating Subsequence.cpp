#include <bits/stdc++.h>
using namespace std;
 
int LCS(string x,string y,int m,int n){
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
            if(x[i-1] == y[j-1] && i!=j){                 // Code Variation
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int32_t main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    while(t-- > 0)
    {
        int m;
        cin>>m;
        string x;
        cin>>x;
        string y = x;               // Code Variation. (Passing same string in LCS function)
        int n = m;
        int ans = LCS(x,y,m,n);
        cout<<ans<<endl;
    }
	return 0;
}
