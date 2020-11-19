#include <iostream>
using namespace std;

int countBits(int n){
    int ans = 0;
    while(n>0){
        ans += (n&1);
        n = n>>1;
    }
    return ans;
}

int countBitsFast(int n){
    int ans=0;
    while(n>0){
        n &= (n-1);
        ans++;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<countBits(n)<<endl;               // method 1
    cout<<countBitsFast(n)<<endl;           // method 2
    cout<<__builtin_popcount(n)<<endl;      // method 3
}
