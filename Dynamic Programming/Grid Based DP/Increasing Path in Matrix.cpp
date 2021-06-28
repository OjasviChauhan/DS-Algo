// https://www.interviewbit.com/problems/increasing-path-in-matrix/

int Solution::solve(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();

    if(r==1 and c==1) return 1;
    if(A[0][0] > A[1][0] and A[0][0] > A[0][1]) return -1;

    int dp[r][c];
    dp[0][0] = 1;

    for(int i=1; i < r; i++){
        if(A[i][0] > A[i-1][0] and dp[i-1][0] != INT_MAX){
            dp[i][0] = dp[i-1][0] + 1;
        }
        else dp[i][0] = INT_MAX;
    }
    for(int j=1; j<c; j++){
        if(A[0][j] > A[0][j-1] and dp[0][j-1] != INT_MAX){
            dp[0][j] = dp[0][j-1] + 1;
        }
        else dp[0][j] = INT_MAX;
    }

    for(int i=1; i < r; i++){
        for(int j=1; j < c; j++){
            if(A[i][j] > A[i-1][j] and A[i][j] > A[i][j-1] and dp[i-1][j] != INT_MAX
            and dp[i][j-1] != INT_MAX)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
            }
            else if(A[i][j] > A[i-1][j] and dp[i-1][j] != INT_MAX){
                dp[i][j] = dp[i-1][j] + 1;
            }
            else if(A[i][j] > A[i][j-1] and dp[i][j-1] != INT_MAX) {
                dp[i][j] = dp[i][j-1] + 1;
            }
            else dp[i][j] = INT_MAX;
        }
    }
    return dp[r-1][c-1] == INT_MAX ? -1 : dp[r-1][c-1];
}
