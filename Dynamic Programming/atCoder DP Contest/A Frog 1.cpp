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
 
int solve(int A[],int n){
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(A[1]-A[0]);
    for(int i=2;i<n;i++){
        int op1 = dp[i-2]+ abs(A[i]-A[i-2]);
        int op2 = dp[i-1]+ abs(A[i]-A[i-1]);
        dp[i] = min(op1,op2);
    }
    return dp[n-1];
}
 
int32_t main(){
    fast;
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<solve(A,n)<<endl;
	return 0;
}
