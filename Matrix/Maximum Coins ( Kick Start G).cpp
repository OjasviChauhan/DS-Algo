// https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a23

// I have used (row - col) as a base to differentiate all diagonal groups and then stored their sum in a map.
// After that their maximum value will be our final answer.


#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define int long long
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
int mod=1000000007;

int32_t main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    int z=1;
    while(t-- > 0)
    {
        int n;
        cin>>n;
        int mat[n][n];
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                mp[i-j] += x;
            }
        }
        int ans = 0;
        for(auto p:mp){
            ans = max(ans,p.second);
        }
        cout<<"Case #"<<z<<": ";
        cout<<ans<<endl;
        z++;
    }
	return 0;
}
