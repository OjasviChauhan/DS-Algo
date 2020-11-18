#include <bits/stdc++.h>
using namespace std;

bool isOdd(int n){
    return n&1;
}

int get_ith_bit(int n,int i){
    int mask = 1<<i;
    int bit = (n&mask)>0 ? 1 : 0;
    return bit;
}

int set_ith_bit(int n,int i){
    int mask = 1<<i;
    int ans = n|mask;
    return ans;
}

void clear_ith_bit(int &n,int i){
    int mask = ~(1<<i);
    n &= mask;
}

void update_ith_bit(int &n,int i,int v){
    // clear ith bit first
    int mask1 = ~(1<<i);
    n &= mask1;

    // then perform OR operation with mask2
    int mask2 = v<<i;
    n |= mask2;
}

int main() {
    int n=5;
    int i;
    cin>>i;
    cout<<get_ith_bit(n,i)<<endl; // give you the ith bit 0 or 1
    cout<<set_ith_bit(n,i)<<endl; // set ith bit to 1
    clear_ith_bit(n,i);           // clear ith bit and make it 0
    cout<<n<<endl;
    update_ith_bit(n,2,0);        // update ith bit with value in v
    update_ith_bit(n,3,1);
    cout<<n<<endl;

    return 0;
}
