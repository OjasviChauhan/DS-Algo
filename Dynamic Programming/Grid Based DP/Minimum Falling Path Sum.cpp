// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        
        int dp[r][c];
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0){
                    dp[i][j] = A[i][j];
                }
                else if(j==0){
                    dp[i][j] = A[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==c-1){
                    dp[i][j] = A[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
                else if(j>0 and j<c-1)
                    dp[i][j] = A[i][j] + min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
                if(i==r-1 and j>0){
                    dp[i][j] = min(dp[i][j],dp[i][j-1]);
                }
            }
        }
        return dp[r-1][c-1];
    }
};
