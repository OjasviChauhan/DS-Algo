#include <bits/stdc++.h>
using namespace std;

void solve(int n,int one,int zero,string op){
    if(n==0){
        cout<<op<<" "<<endl;
        return;
    }
    string op1 = op;
    op1 += '0';
    solve(n-1,one,zero+1,op1);
    
    if(op[op.length()-1]!='1'){
        string op2 = op;
        op2 += '1';
        solve(n-1,one+1,zero,op2);
    }
}

int main(){
    int n;
    cin>>n;
    int one=0;
    int zero=0;
    string op="";
    solve(n,one,zero,op);
}
