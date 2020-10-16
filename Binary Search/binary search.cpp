#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int binarySearch(int A[],int n,int k){
    int start = 0;
    int end = n-1;
    
    while(start<=end){
        int mid = start + (end-start)/2; //to avoid overflow condition
        if(A[mid]==k){
            return 1;
        }
        else if(k<A[mid]){
            end = mid-1;
        }
        else if(k>A[mid]){
            start = mid+1;
        }
    }
    return -1;
}

int32_t main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    while(t-- > 0)
    {
        int n,k;
        cin>>n>>k;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        cout<<binarySearch(A,n,k)<<endl;
    }
	return 0;
}
