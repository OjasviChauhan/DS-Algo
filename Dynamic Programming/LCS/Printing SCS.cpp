#include <bits/stdc++.h>
using namespace std;
 
string LCS(string x,string y,int m,int n){
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
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    
    int i=m,j=n;
    string s="";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s += x[i-1];
            i--; j--;
        }
        else if(x[i-1]>y[j-1]){
            s += x[i-1];                             // Code Variation.
            i--;
        }
        else{
            s += y[j-1];                             // Code Variation.
            j--;
        }
    }
    while(i>0){                                      // Code Variation.
        s += x[i-1];                                 // Code Variation.
        i--;                                         // Code Variation.
    }
    while(j>0){                                      // Code Variation.
        s += y[j-1];                                 // Code Variation.
        j--;                                         // Code Variation.
    }
    reverse(s.begin(),s.end());
    return s;
}

int32_t main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    while(t-- > 0)
    {
        string x,y;
        cin>>x>>y;
        int m = x.size();
        int n = y.size();
        string ans = LCS(x,y,m,n);	                  // Code Variation.
        cout<<ans<<endl;
    }
	return 0;
}
