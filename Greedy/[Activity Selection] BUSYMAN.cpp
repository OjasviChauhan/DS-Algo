// https://www.spoj.com/problems/BUSYMAN/

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

vector<pair<int,int>> v;

bool compare(pair<int,int> p1, pair<int,int> p2){
	return p1.second < p2.second;
}

int solve(vector<pair<int,int>> &v){
	sort(v.begin(), v.end(), compare);

	int ans=1;
	int end = v[0].second;
	for(int i=1;i<v.size();i++){
		if(v[i].first >= end){
			ans++;
			end = v[i].second;
		}
	}
	return ans;
}


int32_t main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
        
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	v.clear();
    	
    	while(n--){
    		int m,n;
    		cin>>m>>n;
    		v.push_back({m,n});
    	}
    	cout<<solve(v)<<endl;
    }

    return 0;
}
