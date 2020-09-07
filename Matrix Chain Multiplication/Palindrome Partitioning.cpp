#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int static dp[1001][1001];

bool isPalindrome(string s,int i,int j){
    if(i>=j)
        return true;

    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
 
int solve(string s,int i,int j){
    // Base Case
    if(i>=j)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
        
    // Lookup
    if(dp[i][j]!= -1)
        return dp[i][j];
    
    // K loop scheme
    int mn = INT_MAX;    
    for(int k=i;k<=j-1;k++){
        int temp = 1 + solve(s,i,k) + solve(s,k+1,j);
        if(temp<mn)
            mn=temp;
    }
    // return after storing
    return dp[i][j] = mn;
}

int32_t main(){
ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int i=0;
        int j=s.length()-1;
        
        memset(dp,-1,sizeof dp);
        cout<<solve(s,i,j)<<endl;
    }
	return 0;
}
