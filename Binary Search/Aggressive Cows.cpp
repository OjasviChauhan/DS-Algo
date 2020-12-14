// https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define endl '\n'
#define int long long
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
int mod=1000000007;

bool check(int A[],int n,int c,int k){
	int count = 1;
	int x = A[0];
	for(int i=1;i<n;i++){
		if(A[i] >= x+k){
			count++;
			x = A[i];
		}
		if(count==c) return true;
	}
	if(count<c) return false;
	return true;
}

void solve()
{
  	int n,c;
  	cin>>n>>c;
  	int A[n];
  	for(int i=0;i<n;i++){
  		cin>>A[i];
  	}
        sort(A,A+n);
    
  	int l = 0;
  	int r = A[n-1] - A[0];
  	int ans;
  	
  	while(l<=r)
  	{
  		int mid = (l+r)/2;
  		ans = mid;
  		if(check(A,n,c,mid)) 
  			l = mid+1;
  		else 
  			r = mid-1;
  	}
  	cout<<ans<<endl;
}

int32_t main(){
    fast;
    int t;
    cin>>t;
    while(t--)
    {
       solve(); 
    }
	return 0;
}
