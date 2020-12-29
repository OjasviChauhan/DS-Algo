#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int subsetSum(int arr[],int sum,int n){
    int dp[n+1][sum+1];
    for(int j=0;j<=sum;j++){
    	dp[0][j] = 0;
    }
	
    dp[0][0] = 1;
    int zeros=0;
    for(int i=1;i<=n;i++){
    	if(A[i-1]==0) zeros++;
        dp[i][0] = pow(2,zeros);
    }
    	
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=sum;j++){
    		if(arr[i-1]<=j){
    			dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
    		}
    		else{
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }
    return dp[n][sum];
}
 
int32_t main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    while(t-- > 0)
    {
    	int n;
    	cin>>n;
    	int arr[n];
    	fl(i,0,n){
    		cin>>arr[i];
    	}
    	int sum;
    	cin>>sum;
        cout<<subsetSum(arr,sum,n)<<endl;    
    }
    return 0;
}
