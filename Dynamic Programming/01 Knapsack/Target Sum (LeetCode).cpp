class Solution {
public: 
    int solve(vector<int> &A,int s,int n){
        int dp[n+1][s+1];
        for(int j=1;j<=s;j++){
            dp[0][j] = 0;
        }
        
        dp[0][0] = 1;
        int zeros=0;
        for(int i=1;i<=n;i++){
            if(A[i-1]==0) zeros++;
            dp[i][0] = pow(2,zeros);
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(A[i-1]<=j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-A[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        
        if((sum%2!=0 && S==0) || S>sum) return 0;
        if((S+sum)%2!=0) return 0;
        
        int ss = (S+sum)/2;
        return solve(nums,ss,n);
    }
};
