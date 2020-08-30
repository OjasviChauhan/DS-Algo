#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    string x,y;
	    cin>>x>>y;
	    
	    //LCS code
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
	    
	    // code for printing lcs
	    int i=m,j=n;
	    string s="";
	    while(i>0 && j>0){
	        if(x[i-1]==y[j-1]){
	            s += x[i-1];
	            i--; j--;
	        }
	        else if(dp[i-1][j] > dp[i][j-1] ){
	            i--;
	        }
	        else j--;
	    }
	    reverse(s.begin(),s.end());
	    cout<<s<<endl;
	}
}
