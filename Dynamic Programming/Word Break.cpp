// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ss;
        for(string str : wordDict){
            ss.insert(str);
        }
        
        if(ss.size() == 0) return false;
        
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(dp[j]) {
                    string word = s.substr(j, i-j);
                    if(ss.find(word) != ss.end()){
                        dp[i] = true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};
