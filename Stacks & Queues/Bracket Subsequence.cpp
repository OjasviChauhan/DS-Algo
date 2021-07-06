// https://codeforces.com/contest/1023/problem/C

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<bool> used(n, false);
    stack<int> st;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else {
            used[st.top()] = true;
            used[i] = true;
            st.pop();
            cnt += 2;
        }
        if (cnt == k) break;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            cout << s[i];
        }
    }
}

int32_t main() {
    fast;

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
