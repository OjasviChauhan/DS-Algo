// https://leetcode.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    int m = A.length(), n = B.length();
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++){
        dp[i][0] = i;
    }

    for(int i=0; i<=n; i++){
        dp[0][i] = i;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}
