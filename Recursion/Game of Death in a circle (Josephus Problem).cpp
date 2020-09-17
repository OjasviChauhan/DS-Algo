/*
Problem Statement : https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0
*/


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

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
