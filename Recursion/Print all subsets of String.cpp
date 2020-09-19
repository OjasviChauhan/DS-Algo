#include <bits/stdc++.h>
using namespace std;

void solve(string ip,string op){
    if(ip.length()==0){
        cout<<op<<endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2 += ip[0];

    solve(ip.substr(1,ip.length()),op1);
    solve(ip.substr(1,ip.length()),op2);
}

int main(){
    string ip;
    cin>>ip;
    string op="";
    solve(ip,op);
}
