// https://hack.codingblocks.com/app/practice/3/1039/problem

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

    vector<int> p(1000005,1);
    p[0] = p[1] = 0;

    for(int i = 2; i*i <= 1000000; i++){
        if(p[i]){
            for(int j = i*i; j <= 1000000; j += i){
                p[j] = 0;
            }
        }
    }

    int cp[1000005] = {0};
    for(int i=1; i <= 1000000 ; i++){
        cp[i] = cp[i-1] + p[i];
    }

    int t;
    cin >> t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        cout << cp[b] - cp[a-1] << endl; 
    }
    return 0;
}
