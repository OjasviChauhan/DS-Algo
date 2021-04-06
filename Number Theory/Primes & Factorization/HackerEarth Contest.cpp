#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> p(2000005, 1);
vector<long long>f(2000005, -1);
vector<int> prime;

void prime_sieve() {
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 2000000; i++) {
		if (p[i] == 1) {
			for (int j = i * i; j <= 2000000; j += i) {
				p[j] = 0;
			}
		}
	}

	for (int i = 2; i <= 2000000; i++) {
		if (p[i]) prime.push_back(i);
	}
}

long long calculate_f(int n) {
	if (n == 1) return 0;

	if (f[n] != -1) {
		return f[n];
	}

	else if (p[n]) {
		return f[n] = 1;
	}

	else {
		int i = 0;
		while (n % prime[i] != 0) {
			i++;
		}
		int x = prime[i];
		int y = n / prime[i];
		return f[n] = ((y * calculate_f(x)) % 998244353 + (x * calculate_f(y)) % 998244353) % 998244353;
	}
	return 0;
}

long long strange_sum (int L, int R) {
	long long ans = 0;
	for (int i = R; i >= L; i--) {
		if (p[i]) {
			ans = (ans + calculate_f(i)) % 998244353;
		}
		else {
			for (int j = 1; j * j <= i; j++) {
				if (i % j == 0) {
					if (i / j == j) {
						ans = (ans + calculate_f(j)) % 998244353;
					}
					else {
						ans = (ans + calculate_f(j)) % 998244353;
						ans = (ans + calculate_f(i / j)) % 998244353;
					}
				}
			}
		}
	}
	return ans % 998244353;
}

int32_t main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	prime_sieve();
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++)
	{
		int L;
		cin >> L;
		int R;
		cin >> R;

		long long out_;
		out_ = strange_sum(L, R);
		cout << out_;
		cout << "\n";
	}
}
