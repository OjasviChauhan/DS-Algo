// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int dp[k+1][n];
        
        for(int i=0;i<k+1;i++){
            int maxThusFar = INT_MIN;
            for(int j=0;j<n;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else
                {
                    // if you wish NOT to sell on this day and 
                    // continue with the previous day profit.
                    int op1 = dp[i][j-1];
                    
                    // but if you plan to sell on this day then you would
                    // need the previous minimum purchase day in order
                    // to maximise this day's sell value. You'd also need to
                    // add the previous transaction's profit.
                    maxThusFar = max(maxThusFar, -prices[j-1]+dp[i-1][j-1]);
                    int op2 = prices[j] + maxThusFar;
                    
                    // At the end you need to take max of op1 and op2.
                    dp[i][j] = max(op1,op2);
                }
            }
        }
        return dp[k][n-1];
    }
};
