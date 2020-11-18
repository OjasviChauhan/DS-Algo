#include <bits/stdc++.h>
using namespace std;

int clearLastIBits(int n,int i){
    int mask = (-1<<i);
    return n & mask;
}

int clear_I_to_J(int n,int i,int j){
    int A = -1<<(j+i);
    int B = ~(-1<<i);
    int mask = A|B;
    n &= mask;
    return n;
}

int main() {
    int n;
    cin>>n;
    int i,j;
    cin>>i>>j;
    cout<<clearLastIBits(n,i)<<endl;
    cout<<clear_I_to_J(n,i,j)<<endl;
    
    return 0;
}
