// https://www.interviewbit.com/old/problems/kingdom-war/

int Solution::solve(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    int ans = INT_MIN;
    
    int dp[r+1][c+1];
    memset(dp,0,sizeof(dp));  
    
    // making suffix sum matrix and taking their max sum.
    for(int i=r-1; i>=0; i--){
        for(int j=c-1; j>=0; j--){
            dp[i][j] = A[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
