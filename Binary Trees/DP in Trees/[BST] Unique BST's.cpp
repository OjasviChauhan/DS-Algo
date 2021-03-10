// https://practice.geeksforgeeks.org/problems/unique-bsts/0#

// In this problem we just have to find the catalan number.

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


int ncr(int n, int k){
    int res = 1; 
    if (k > n - k) 
        k = n - k; 
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res;
}

void solve()
{
    int n;
    cin>>n;
    cout<<ncr(2*n,n)/(n+1)<<endl;
}

int32_t main(){
    fast;   
    int t;
    cin>>t;
    while(t--)
    {
       solve(); 
    }
	return 0;
}
