// https://www.codechef.com/APRIL21C/problems/KAVGMAT

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
    int n, m, k;
    cin >> n >> m >> k;
    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = A[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int cnt = 0;
    for (int K = 1; K <= min(n, m); K++) {

        for (int i = K; i <= n; i++) {
            double avg = (dp[i][m] - dp[i - K][m] - dp[i][m - K] + dp[i - K][m - K]) / (double)(K * K);

            if (avg >= (double)k) {

                int start = K;
                int end = m;
                int val = 0;
                
                // Using Binary Search to find that threshold element.
                while (start <= end) {
                    int mid = (start + end) / 2;
                    int sum = (dp[i][mid] - dp[i - K][mid] - dp[i][mid - K] + dp[i - K][mid - K]);
                    double avg = sum / (double)(K * K);

                    if (avg < k) start = mid + 1;
                    else {
                        val = mid;
                        end = mid - 1;
                    }
                }
                cnt += m - val + 1;
            }
        }
    }
    cout << cnt << endl;
}

int32_t main() {
    fast;

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
