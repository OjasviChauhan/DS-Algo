// https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int r=mat.size();
        int c=mat[0].size();
        
        int dp[r+1][c+1];
        memset(dp,0,sizeof(dp));     
        
        // making prefix matrix
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        auto ans = mat;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                int x1 = max(1,i-K);
                int x2 = min(r,i+K);
                int y1 = max(1,j-K);
                int y2 = min(c,j+K);
                
                ans[i-1][j-1] = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
            }
        }
        return ans;
    }
};
