// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int mx = 0;
        for (int i : nums) {
            cnt[i] += i;
            mx = max(mx, i);
        }
        int dp[mx + 1];
        dp[0] = cnt[0];
        dp[1] = cnt[1];
        for (int i = 2; i < mx + 1; i++) {
            dp[i] = max(cnt[i] + dp[i-2], dp[i-1]);
        }
        return dp[mx];
    }
};
