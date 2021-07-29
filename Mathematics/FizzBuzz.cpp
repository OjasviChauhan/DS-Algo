#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define endl '\n'
#define int long long
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
int mod = 1000000007;

void Solution1(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 and i % 5 == 0)
            cout << "FizzBuzz" << endl;
        else if (i % 3 == 0)
            cout << "Fizz" << endl;
        else if (i % 5 == 0)
            cout << "Buzz" << endl;
        else
            cout << i << endl;
    }
}

void Solution2(int n) {
    for (int i = 1; i <= n; i++) {
        string d = "";
        if (i % 3 == 0) d += "Fizz";
        if (i % 5 == 0) d += "Buzz";
        if (d == "")
            cout << i << endl;
        else
            cout << d << endl;
    }
}

void Solution3(int n) {
    int c3 = 0, c5 = 0;
    for (int i = 1; i <= n; i++) {
        c3++;
        c5++;
        string d = "";
        if (c3 == 3) {d += "Fizz"; c3 = 0;}
        if (c5 == 5) {d += "Buzz"; c5 = 0;}
        if (d == "") cout << i << endl;
        else cout << d << endl;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    Solution1(n);
    Solution2(n);
    Solution3(n);

    return 0;
}
