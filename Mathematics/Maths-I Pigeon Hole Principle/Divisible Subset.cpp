// https://www.codechef.com/problems/DIVSUBS

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

void solve() {
    int n;
    cin >> n;
    int A[n], pre[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (i == 0) pre[i] = A[i];
        else pre[i] = pre[i - 1] + A[i];
        pre[i] %= n;
    }

    //print(pre);
    vector<vector<int>> freq(n);
    for (int i = 0; i < n; i++) {
        if (pre[i] == 0) {
            cout << i + 1 << endl;
            for (int j = 0; j <= i; j++) {
                cout << j + 1 << " ";
            }
            return;
        }
        freq[pre[i]].push_back(i);
        if (freq[pre[i]].size() == 2) {
            cout << i - freq[pre[i]][0] << endl;
            for (int j = freq[pre[i]][0] + 1; j <= i; j++) {
                cout << j + 1 << " ";
            }
            return;
        }
    }
    cout << -1 << endl;
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
        solve();

    return 0;
}
