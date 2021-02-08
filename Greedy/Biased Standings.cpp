// https://www.spoj.com/problems/BAISED/

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

int32_t main(){
    fast;
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int rank, count[n+1];
    	memset(count,0,sizeof count);
    	string team;

    	for(int i=0;i<n;i++){
    		cin>>team>>rank;
    		count[rank]++;
    	}

    	int ans=0;
    	int k=1;
    	for(int i=1;i<=n;i++){
    		while(count[i]){
    			ans += abs(i-k);
    			count[i]--;
    			k++;
    		}
    	}
    	cout<<ans<<endl;
    }
	return 0;
}
