/*
THE LARGEST NUMBER OF VACCINES
A disease has spread in your country that does not have
any vaccines. The health department of your country is
working to create its vaccine. The limitation to create
vaccines is the cost that is required to create an effective
vaccine.

The scientists of the department have created 9 samples
that are numbered from 1 to 9. Each vaccine is
associated with a cost. The cost is denoted by an array X
where Xi denotes the cost of ith sample. The health dept
has been assigned N units of money to spend. This
amount of money must be used to create stocks of
vaccines that can be distributed among different
hospitals that are situated at different locations in your
country.

You are required to find the largest number of stocks
possible that can be formed by using the N units of
money, if it is not possible to form such a stock of
vaccines, then print -1.

Constraints:

1 <= T <= 10^3
1 <= N <= 10^4
1 <= Xi <= 10^3

input:

4
5
9 4 2 2 6 3 2 2 1
2
5 11 2 2 5 8 9 10 19
5
9 9 9 9 9 9 9 9 9 9
32
7 8 9 8 7 9 8 8 10

output

99999
4
-1
9855

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define int long long
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
int mod = 1000000007;

string solve() {
    int tar;
    cin >> tar;
    vector<int> cost;
    for (int i = 0; i < 9; i++) {
        int temp;
        cin >> temp;
        cost.push_back(temp);
    }
    vector<int> dp(tar + 1, -10000);
    dp[0] = 0;
    for (int i = 1; i <= tar; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (i >= cost[j]) {
                dp[i] = max(dp[i], dp[i - cost[j]] + 1);
            }
        }
    }
    print(dp);
    if (dp[tar] < 0) {
        return "-1";
    }

    string res = "";
    for (int i = 8; i >= 0; --i) {
        while (tar >= cost[i] && dp[tar] == dp[tar - cost[i]] + 1) {
            res.push_back('1' + i);
            tar -= cost[i];
        }
    }
    return res;
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
        cout << solve() << endl;
    }

    return 0;
}
