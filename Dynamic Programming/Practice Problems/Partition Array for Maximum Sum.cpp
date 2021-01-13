// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        int n = A.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++){
            int curMax = 0;
            for(int j=1;j<=k && i-j+1>=0;j++){
                curMax = max(curMax,A[i-j+1]);
                int cur = (i>=j ? dp[i-j] : 0) + j*curMax;
                dp[i] = max(dp[i],cur);
            }
        }
        return dp[n-1];
    }
};
