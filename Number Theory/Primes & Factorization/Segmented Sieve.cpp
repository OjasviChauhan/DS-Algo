// https://www.spoj.com/problems/PRIME1/
// https://www.codechef.com/problems/PRIME1

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const int N = 100000;
vector<int> p(N + 1, 1);
vector<int> prime;

void sieve() {
    for (long i = 2; i <= N; i++) {
        if (p[i]) {
            prime.push_back(i);
            for (long j = i * i; j <= N; j += i) {
                p[j] = 0;  // not prime
            }
        }
    }
}

void segmented_sieve() {
    int m, n;
    cin >> m >> n;

    // always take "bool-array" for segmented array
    // Do not take any kind of vector or int-array, coz
    // that will lead to runtime errors on large test cases.
    bool segment[n - m + 1];
    for (int i = 0; i < n - m + 1; i++) {
        segment[i] = 1;
    }

    for (auto i : prime) {
        if (i * i > n) break;

        int start = (m / i) * i;
        if (i >= m and i <= n) {
            start = 2 * i;
        }

        // mark all multiples of i, in the range: start to n as not prime.
        for (int j = start; j <= n; j += i) {
            segment[j - m] = 0;
        }
    }

    for (int i = m; i <= n; i++) {
        if (segment[i - m] and i != 1) {
            cout << i << endl;
        }
    }
    cout << endl;
}

int main() {
    fast;

    sieve();

    int t;
    cin >> t;
    while (t--)
        segmented_sieve();

    return 0;
}
