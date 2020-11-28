/*
The Planet Earth is under a threat from the aliens of the outer space and the 
Marvel Avengers team is busy fighting against them. Meanwhile, The Incredible Hulk
has to defeat an enemy who is N steps above the level where he is standing 
(assume it as the 0th level). Hulk, because of his incredible jumping ability 
can take jumps in power of 2. In order to defeat the enemy as quickly as possible
he has to reach the Nth step in minimum moves possible. Help Hulk to find the same
and contribute in saving the Mother Earth.
*/



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


int32_t main() {
	fast;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<__builtin_popcount(n)<<endl;
	}

    return 0;
}
