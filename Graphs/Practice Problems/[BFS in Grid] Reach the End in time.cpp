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

bool isValid(int i,int j,int n,int m){
	if(i>=0 and i<n and j>=0 and j<m){
		return true;
	}
	return false;
}

int count(vector<string>G, vector<vector<bool>>& vis,int i,int j,int n,int m){
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};

	vis[i][j] = true;
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{i,j}});

	int X,Y;

	while(!q.empty()){
		auto t = q.front();
		q.pop();

		int dist = t.ff;
		int x = t.ss.ff;
		int y = t.ss.ss;

		if(x==n-1 and y==m-1) return dist;

		for(int i=0;i<4;i++){
			X = x + dx[i];
			Y = y + dy[i];
			if(isValid(X,Y,n,m) and G[X][Y]=='.' and !vis[X][Y]){
				vis[X][Y] = true;
				q.push({dist+1,{X,Y}});
			}
		}
	}
	return -1;
}

int32_t main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<string> G;

    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;
    	G.pb(s);
    }
    int k;
    cin>>k;

    int r = G.size();
    int c = G[0].size();

    vector<vector<bool>> vis(r,vector<bool>(c,false));

    int ans = count(G,vis,0,0,r,c);
    cout<<ans<<endl;
    if(ans<=k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

	return 0;
}
