// https://www.interviewbit.com/old/problems/min-cost-path/

int get(char c) {
    if (c == 'U') return 0;
    if (c == 'R') return 1;
    if (c == 'D') return 2;
    return 3;
}

int Solution::solve(int A, int B, vector<string> &C) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, get(C[0][0]), 0, 0});

    vector<vector<int>>dist(A, vector<int>(B, INT_MAX));
    dist[0][0] = 0;

    int dx[4] = { -1, 0, 1, 0}; // URDL
    int dy[4] = {0, 1, 0, -1}; // URDL

    while (!q.empty()) {
        auto f = q.top();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = f[2] + dx[i];
            int y = f[3] + dy[i];

            if (x >= 0 && y >= 0 && x < A && y < B) {

                if (i == f[1]) {
                    if (dist[x][y] > dist[f[2]][f[3]]) {
                        dist[x][y] = dist[f[2]][f[3]];
                        q.push({dist[x][y], get(C[x][y]), x, y});
                    }
                }
                else {
                    if (dist[x][y] > dist[f[2]][f[3]] + 1) {
                        dist[x][y] = dist[f[2]][f[3]] + 1;
                        q.push({dist[x][y], get(C[x][y]), x, y});
                    }
                }
            }
        }

    }
    return dist[A - 1][B - 1];
}
