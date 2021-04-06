// https://hack.codingblocks.com/app/practice/1/137/problem

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define MAX 100000000

int solve(int n, int k) {
    int ans = MAX;
    int occ = 0;

    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            occ = 0;
            while (k % i == 0) {
                occ++;
                k /= i;
            }

            // Find the powers of 'i' in n! side by side.
            int cnt = 0;
            int p = i;
            while (p <= n) {
                cnt += n / p;
                p *= i;
            }
            ans = min(ans, cnt / occ);
        }
    }

    // we may have a case when still a prime factor is left.
    if (k != 1) {
        int p = k;
        int cnt = 0;
        while (p <= n) {
            cnt += n / p;
            p *= k;
        }
        ans = min(ans, cnt);
    }

    if (ans == MAX)
        return 0;

    return ans;
}

int32_t main() {
    fast;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    int n, k;
    while (t--) {
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }

    return 0;
}
