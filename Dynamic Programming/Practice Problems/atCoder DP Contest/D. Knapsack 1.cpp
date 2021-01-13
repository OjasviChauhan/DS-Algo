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
 
int solve(int w[],int v[],int N,int W){
    int dp[N+1][W+1];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(w[i-1]<=j){
                dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], 
                               dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}
 
int32_t main(){
    fast;
    int N,W;
    cin>>N>>W;
    int w[N],v[N];
    for(int i=0;i<N;i++){
        cin>>w[i]>>v[i];
    }
    cout<<solve(w,v,N,W)<<endl;
	return 0;
}
