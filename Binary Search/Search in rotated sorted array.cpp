#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define int long long
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
typedef vector<int> VI;
int mod=1000000007;

int findMinIndex(int A[],int n,int k){
    int start = 0;
    int end = n-1;
    
    while(start<=end){
        int mid = start + (end-start)/2;
        int nextToMid = (mid+1)%n;
	      int prevToMid = (mid+n-1)%n;
        
        if(A[mid]<A[prevToMid] && A[mid]<A[nextToMid]){
            return mid;
        }
        else if(A[start] <= A[mid] && A[mid] <= A[end]){
            return start;
        }
        else if(A[start]<=A[mid]){
            start = mid+1;
        }
        else if(A[mid]<=A[end]){
            end = mid-1;
        }
    }
    return -1;
}

int binarySearch(int A[],int start,int end,int k){
    while(start<=end){
        int mid = (start+end)/2;
        if(A[mid]==k) return mid;
        else if(k>A[mid]) start=mid+1;
        else end = mid-1;
    }
    return -1;
}

int32_t main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int k;
        cin>>k;
        
        int index = findMinIndex(A,n,k);
        int l = binarySearch(A,0,index-1,k);
        int r = binarySearch(A,index,n-1,k);
        
        if(l!=-1) cout<<l<<endl;
        else if(r!=-1) cout<<r<<endl;
        else cout<<-1<<endl;
    }
	return 0;
}
