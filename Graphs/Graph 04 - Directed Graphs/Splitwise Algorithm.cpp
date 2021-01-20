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
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
       
    int n,m; 
    cin>>n>>m;
    vector<int> mode(n,0);
    while(m--){
    	int a,b,wt;
    	cin>>a>>b>>wt;
    	mode[a] -= wt;
    	mode[b] += wt;
    }

    multiset<int> ms;
    for(auto x:mode){
    	if(x!=0)
    	    ms.insert(x);
    }

    int tr=0;
    while(!ms.empty()){
    	auto lo = ms.begin();
    	auto hi = prev(ms.end()); 
    	ms.erase(lo);
    	ms.erase(hi);
    	
    	int debit = *lo;
    	int credit = *hi;

    	int amt = min(-debit,credit);
    	tr++;

    	debit += amt;
    	credit -= amt;
    	if(debit!=0) ms.insert(debit);
    	if(credit!=0) ms.insert(credit);
	}

	cout<<tr<<endl;

	return 0;
}
