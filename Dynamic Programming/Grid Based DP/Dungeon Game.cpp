// https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &A) {
        int r = A.size();
        int c = A[0].size();
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, INT_MAX));
        dp[r][c - 1] = 1;
        dp[r - 1][c] = 1;
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - A[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }
};
