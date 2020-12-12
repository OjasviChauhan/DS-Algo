// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int dp[r][c];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0) dp[i][j] = matrix[i][j];
                else{
                    if(matrix[i][j]){
                        dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                count += dp[i][j];
            }
        }
        return count;
    }
};
