#include <bits/stdc++.h>
using namespace std;

void solve(string n,string op,vector<string> &v){
    if(n.length()==0){
        v.push_back(op);
        return;
    }
    string op1 = op;
    int k = n[0]-48;                    // taking first digit & converting in into int
    char c = k+64;                      // changing int into char using ascii values
    op1 += c;
    solve(n.substr(1,n.length()),op1,v);    //first recursive call
    
    if(n.length()>1){                   
        string op2 = op;
        string s = n.substr(0,2);        //taking first 2 digits
        int k1 = stoi(s);               // converting them into integer
        if(k1<=26){
            char c1 = k1+64;
            op2 += c1;
            solve(n.substr(2,n.length()),op2,v);    //second recursive call
        }
    }
}

int main() {
    string n;
    cin>>n;
    string op="";
    vector<string> v;
    solve(n,op,v);
    for(auto x:v){
        cout<<x<<endl;
    }
}
