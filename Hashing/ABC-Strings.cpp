// https://www.codechef.com/problems/ABCSTR

#include <bits/stdc++.h>
using namespace std;
#define int        long long int 
#define endl       "\n"
#define pb         push_back
#define ff         first
#define ss         second
#define mp         make_pair

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n;
        n = s.length();
        int a=0,b=0,c=0;
        int ans=0;
        map<vector<int>,int>mp;
        mp[{0,0,0}]=1;
        for(int i=0;i<n;i++){
            if(s[i]=='A')a++;
            else if(s[i]=='B')b++;
            else c++;

            int mini = min({a,b,c});
            a -= mini, b -= mini, c -= mini;
            ans += mp[{a,b,c}];
            mp[{a,b,c}]++;
        }
        cout<<ans<<endl;

    }
    return 0;
}
