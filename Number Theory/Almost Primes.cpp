// https://codeforces.com/problemset/problem/26/A

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

int sieve(int n) {
    int pr[n + 1] = {0};
    for (int i = 2; i <= n; i++) {
        // i is a prime number
        if (pr[i] == 0) {
            for (int j = i; j <= n; j += i) {
                pr[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (pr[i] == 2) {
            ans++;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    cout << sieve(n) << endl;
}

int32_t main() {
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
