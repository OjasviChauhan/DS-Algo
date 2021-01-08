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

class dsu{
public:
    vector<int> par;
    void init(int n){
        par.resize(n);
        iota(par.begin(),par.end(),0);
    }

    int findSet(int i){
        return (par[i]==i) ? i : (par[i]=findSet(par[i]));
    }

    void unionSet(int x,int y){
        x=findSet(x);
        y=findSet(y);
        if(x!=y){
            par[x] = max(par[x],par[y]);
            par[y] = max(par[x],par[y]);
        }
    }

};

int32_t main(){
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    int n,q;
    cin>>n>>q;

    int l[q],r[q],c[q];
    for(int i=0;i<q;i++){
        cin>>l[i]>>r[i]>>c[i];
    }

    dsu G;
    G.init(n+2);
    int res[n+2] = {};

    for(int i=q-1;i>=0;i--){
        // index -> rightmost non colored index
        int index = G.findSet(l[i]);
        while(index<=r[i]){
            res[index] = c[i];
            G.unionSet(index,index+1);
            index = G.findSet(index);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<res[i]<<endl;
    }

    return 0;
}