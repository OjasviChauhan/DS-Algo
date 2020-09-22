#include <bits/stdc++.h>
using namespace std;

void solve(string ip,string op){
    if(ip.length()==0){
        cout<<op<<" ";
        return;
    }
    
    for(int i=0;i<ip.length();i++){
        string op1 = op;
        swap(ip[0],ip[i]);
        op1 += ip[0];
        solve(ip.substr(1,ip.length()), op1);
    }
}

int main(){
	int n;
	cin>>n;
	while(n--){
    	string ip;
    	cin>>ip;
    	string op="";
    	solve(ip,op);
    	cout<<endl;
	}
	return 0;
}
