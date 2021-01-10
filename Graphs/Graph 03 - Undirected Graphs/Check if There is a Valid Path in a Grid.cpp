// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bool visited[n][m];
        memset(visited, 0, sizeof(visited));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if (y == n-1 and x == m-1) return true;
            int &current = grid[y][x];
            if (x > 0 and !visited[y][x-1]) {
                if (current == 1 or current == 3 or current == 5) {
                    int &street = grid[y][x-1];
                    if (street == 2 or street == 3 or street == 5)
                        return false;
                    q.push({y, x-1});
                    visited[y][x-1] = true;
                }
            }
            if (x < m - 1 and !visited[y][x+1]) {
                if (current == 1 or current == 4 or current == 6) {
                    int &street = grid[y][x+1];
                    if (street == 2 or street == 4 or street == 6)
                        return false;
                    q.push({y, x+1});
                    visited[y][x+1] = true;
                }
            }
            if (y > 0 and !visited[y-1][x]) {
                if (current == 2 or current == 5 or current == 6) {
                    int &street = grid[y-1][x];
                    if (street == 1 or street == 5 or street == 6)
                        return false;
                    q.push({y-1, x});
                    visited[y-1][x] = true;
                }
                
            }
            if (y < n-1 and !visited[y+1][x]) {
                if (current == 2 or current == 3 or current == 4) {
                    int &street = grid[y+1][x];
                    if (street == 1 or street == 3 or street == 4)
                        return false;
                    q.push({y+1, x});
                    visited[y+1][x] = true;
                }
            }
        }
        return false;
    }
};
