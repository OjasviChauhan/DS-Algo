#include <bits/stdc++.h>
using namespace std;
#define fl(i, a, b) for (int i = (a); i < (b); i++)
#define flr(i, a, b) for(int i = (a); i >=(b); i--)
#define itr(i, A) for(auto i=A.begin(); i != A.end(); ++i)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define int long long
typedef vector<int> VI;
int mod1=1000000007;
int mod2=67280421310721;
int mod3=998244353;
int INF=1e18;

void solve(vector<int> &v,int k,int index){
    if(v.size()==1){
        cout<<v[0]<<endl;
        return;
    }
    index = (index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,k,index);
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
        vector<int> v;
        int index=0;
        for(int i=0;i<n;i++)
            v.push_back(i+1);
        solve(v,k-1,index);
    }
	return 0;
}
