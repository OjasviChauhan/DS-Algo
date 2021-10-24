/*
Soham is locked in the 2-d type mystery room and he is provided with a keyword and in order to 
escape from the room, he needs to find the maximum times the particular keyword is present in the
room. Soham can traverse east, west, north, south, Diagonal traversal is not possible.

INPUT:
1
3 3
c a r
a r c
c r a
Keyword: car

OUTPUT:
5

*/

#include <bits/stdc++.h>
using namespace std;

int xt[4] = {0, 0, 1, -1};
int yt[4] = {1, -1, 0, 0};

int sol(int x, int y, vector<vector<char>> &v, string &s) {

    int idx = 1;
    queue<pair<int, int>> q;

    int n = v.size();
    int m = v[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vis[x][y] = 1;

    q.push({x, y});

    int ans = 0;
    while (q.size() > 0) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            int xc = q.front().first;
            int yc = q.front().second;

            vis[xc][yc] = 1;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = xc + xt[j];
                int ny = yc + yt[j];

                if (nx >= 0 && nx < v.size() && ny >= 0 && ny < v[0].size()
                        && vis[nx][ny] == 0 && v[nx][ny] == s[idx]) {
                    q.push({nx, ny});
                }

            }
        }

        if (q.size() == 0)
            ans += n;

        idx++;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    string wor;
    cin >> wor;

    vector<pair<int, int>> ind;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == wor[0]) {
                ind.push_back({i, j});
            }
        }
    }

    if (wor.size() == 1) {
        cout << ind.size() << "\n";
        return;
    }

    int ans = 0;

    for (auto i : ind) {
        ans += sol(i.first, i.second, v, wor);
    }

    cout << ans << "\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
