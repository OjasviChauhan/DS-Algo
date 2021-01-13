// https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.size();
        int c = days[n-1]+1;
        
        int dp[3][c];
        memset(dp,0,sizeof(dp));
        int flag[c];
        memset(flag,0,sizeof(flag));
        
        flag[days[0]] = 1;
        dp[0][days[0]] = cost[0];
        
        int k=1;
        for(int j=days[0]+1;j<c;j++){
            if(j==days[k]){
                dp[0][j] = dp[0][j-1] + cost[0];
                flag[j] = 1;
                k++;
            }
            else dp[0][j] = dp[0][j-1];
        }
        
        for(int i=1;i<=2;i++){
            for(int j=1;j<c;j++){
                if(j <= 7 and i==1){
                    dp[i][j] = min(dp[i-1][j],cost[1]);
                }
                else if(j <= 30 and i==2){
                    dp[i][j] = min(dp[i-1][j],cost[2]);
                }
                else if(flag[j]==0){
                    dp[i][j] = dp[i][j-1];
                }
                else{
                    int op1 = dp[i-1][j];
                    int op2 = (j>1) ? dp[i][j-1]+cost[0] : op1;
                    int op3 = (j>7) ? dp[i][j-7]+cost[1] : op2;
                    int op4 = (j>30) ? dp[i][j-30]+cost[2] : op3;
                    dp[i][j] = min(op1, min(op2, min(op3,op4)));
                }
            }
        }
        return dp[2][c-1];
    }
};
