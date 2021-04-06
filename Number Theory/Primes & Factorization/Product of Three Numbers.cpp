// https://codeforces.com/contest/1294/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

void solve(int N) {

    vector<pair<int, int>> factors;

    // Doing Prime Factorization ......
    int n = N;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        if (n % i == 0) {
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            factors.push_back({i, cnt});
        }
        if (factors.size() == 3) break;
    }
    if (n != 1) {
        factors.push_back({n, 1});
    }

    // Now check these conditions .....
    if (factors.size() >= 2) {
        int a = factors[0].first;
        int b = factors[1].first;
        int c = N / (a * b);
        if (c != a and c != b and c > 1) {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
        else cout << "NO" << endl;
    }

    else if (factors.size() == 1 and factors[0].second >= 6) {
        cout << "YES" << endl;
        int a = factors[0].first;
        int b = a * a;
        int c = N / (a * b);
        cout << a << " " << b << " " << c << endl;
    }

    else cout << "NO" << endl;
}

int32_t main() {
    fast;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
