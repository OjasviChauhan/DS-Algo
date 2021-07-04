// https://leetcode.com/problems/longest-increasing-subsequence/


// O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[n];
        for(int i=0;i<n;i++) dp[i] = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


// O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        for(int i = 1; i <= n; i++) dp[i] = INT_MAX;
        dp[0] = INT_MIN;
        
        for(int i = 1; i <= n; i++){
            int idx = lower_bound(dp, dp+n+1, nums[i-1]) - dp;
            dp[idx] = nums[i-1];
        }
        
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(dp[i] == INT_MAX) return cnt;
            cnt++;
        }
        return cnt;
    }
};
