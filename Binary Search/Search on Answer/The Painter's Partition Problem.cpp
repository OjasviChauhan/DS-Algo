// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0#

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

bool isValid(int A[],int mid,int k,int n){
    int sum = 0, painter = 1;
    for(int i=0;i<n;i++){
        sum += A[i];
        if(sum > mid){
            painter++;
            sum = A[i];
        }
        if(painter > k)
            return false;
    }
    return true;
}

int32_t main(){
    fast;
    
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        
        int mx = INT_MIN, sum = 0;
        for(int i=0;i<n;i++){
            sum += A[i];
            mx = max(mx,A[i]);
        }
        
        int start = mx, end = sum;
        int ans;
        
        while(start<=end){
            int mid = end - (end-start)/2;
            if(isValid(A,mid,k,n)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
