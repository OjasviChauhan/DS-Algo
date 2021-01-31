// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0#

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

int solve(string s,int k){
    unordered_map<char,int> mp;
    int start = 0,end = 0,n = s.size();
    if(n<k) return -1;
    int mx = INT_MIN;
    
    for(end=0;end<n;end++){
        mp[s[end]]++;
        if(mp.size()>k){
            while(mp.size()>k){
                mp[s[start]]--;
                if(mp[s[start]] == 0){
                    mp.erase(s[start]);
                }
                start++;
            }
        }
        mx = max(mx,end-start+1);
    }
    return mx;
}

int32_t main(){
    fast;
        
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       int k;
       cin>>k;
       cout<<solve(s,k)<<endl;
    }
	return 0;
}
