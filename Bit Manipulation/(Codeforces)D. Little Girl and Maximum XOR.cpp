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

int pow1(int a,int b){
    int res=1;
    while (b>0){
        if (b&1)
        res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

int32_t main() {
	fast;
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt","r",stdin);
// 		freopen("output.txt","w",stdout);
// 	#endif
	
	int a,b;
	cin>>a>>b;
	int ans=0;
	bool flag = false;

	for(int i=63;i>=0;i--){
		int l = (a>>i);
		int r = (b>>i);
		if(flag){
			ans += pow1(2,i);
		}
        if(l!=r and !flag){
			ans += pow1(2,i);
			flag = true;
		}
	}
	cout<<ans<<endl;

    return 0;
}
