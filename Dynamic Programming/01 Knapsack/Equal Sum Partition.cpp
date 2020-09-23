#include <bits/stdc++.h>
using namespace std;
#define fl(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define int long long
int mod1=1000000007;

bool subsetSum(int arr[],int sum,int n){
    bool dp[n+1][sum+1];

    for(int j=0;j<=sum;j++){
    	dp[0][j] = false;
    }
	for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    	
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=sum;j++){
    		if(arr[i-1]<=j){
    			dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
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
    	int sum=0;
    	fl(i,0,n){
    	    sum += arr[i];
    	}
    	if(sum%2!=0){
    	    cout<<false<<endl;
    	}
    	else{
    	    cout<<subsetSum(arr,sum/2,n)<<endl;
    	}
    }
	return 0;
}
