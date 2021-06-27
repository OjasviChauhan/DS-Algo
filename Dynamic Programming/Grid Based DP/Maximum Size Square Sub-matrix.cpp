// https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/

int Solution::solve(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    int dp[r][c];
    int ans = INT_MIN;

    // Here dp[i][j] will denote the size of binary-square 
    // that can be made upto that sub-problem.
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 or j==0){
                dp[i][j] = A[i][j];
            }
            else if(A[i][j]){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
            else dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans*ans;
}
