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
 
int solve(int A[],int n,int k){
    int dp[n];
    for(int i=1;i<n;i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            int op1 = (i-j>=0) ? dp[i-j]+abs(A[i]-A[i-j]) : abs(A[i]-A[0]);
            dp[i] = min(dp[i],op1);
        }
    }
    //print(dp);
    return dp[n-1];
}
 
int32_t main(){
    fast;
    int n,k;
    cin>>n>>k;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<solve(A,n,k)<<endl;
	return 0;
}
