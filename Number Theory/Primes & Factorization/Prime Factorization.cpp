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

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        if (n % i == 0) {
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            factors.push_back({i, cnt});
        }
    }
    if (n != 1) {
        factors.push_back({n, 1});
    }

    for (auto p : factors) {
        cout << p.ff << "^" << p.ss << endl;
    }
    cout << endl;
}

int32_t main() {
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
