// https://practice.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x/0#

#include<bits/stdc++.h>
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
        
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       
       char M[n][n];
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                cin>>M[i][j];
           }
       }
       
       pair<int,int> dp[n][n];
       int maxMat[n][n];
       memset(maxMat,0,sizeof maxMat);
       int ans=0;
       
       int c=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(M[i][j]=='X')
                    c+=1;  
               else c=0;
               dp[i][j].first = c;
           }
           c=0;
       }
       
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(M[i][j]=='X')
                    c+=1;  
                else c=0;
                dp[i][j].second = c;
            }
            c=0;
        }
       
        int k;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int val = min(dp[i][j].ff, dp[i][j].ss);
                for(k=val;k>=1;k--){
                    if(dp[i][j-k+1].ss >= val and dp[i-k+1][j].ff >= val ){
                        maxMat[i][j] = k;
                        ans = max(ans,maxMat[i][j]);
                        break;
                    }
                    else val--;
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
