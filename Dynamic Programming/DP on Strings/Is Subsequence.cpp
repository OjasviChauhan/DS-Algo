// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {        
        int r = s.size();
        int c = t.size();
        if(r > c) return 0;
        if(r == 0 or c == 0) return 1;
        
        vector<int> dp(r, 0);
        
        int i, j, k = -1;
        for(int i = 0; i < r; i++) {
            for(j = k+1; j < c; j++) {
                if(s[i] == t[j]){
                    dp[i] = j;
                    k = j;
                    break;
                }
            }
            if(j == c) return 0;
        }
        for(int i = r-1; i > 0; i--) {
            if(dp[i-1] > dp[i]) return 0;
        }
        return 1;
    }
};
