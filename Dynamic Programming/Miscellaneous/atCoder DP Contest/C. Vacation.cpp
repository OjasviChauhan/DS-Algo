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
    for(int j=0;j<3;j++){
        dp[0][j] = A[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                dp[i][j] = A[i][j] + max(dp[i-1][j+1],dp[i-1][j+2]);
            }
            else if(j==1){
                dp[i][j] = A[i][j] + max(dp[i-1][j-1],dp[i-1][j+1]);
            }
            else{
                dp[i][j] = A[i][j] + max(dp[i-1][j-1],dp[i-1][j-2]);
            }
        }
    }
    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
 
int32_t main(){
    fast;
    int n;
    cin>>n;
    int A[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
        cin>>A[i][j];
    }
    cout<<solve(A,n)<<endl;
	return 0;
}
