// https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
    int dp[601][101][101] = {};
    
    pair<int,int> calculate(string &s){
        int zero=0, one=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '0')
                zero++;
            else one++;
        }
        return {zero,one};
    }
    
    int solve(int i,vector<pair<int,int>> &v,int zero,int one){
        if(i == v.size() or (zero == 0 and one == 0)) return 0;
        
        if(dp[i][zero][one] != -1)
            return dp[i][zero][one];
        
        if(v[i].first > zero or v[i].second > one)
            return dp[i][zero][one] = solve(i+1,v,zero,one);
        
        int include = 1 + solve(i+1,v,zero-v[i].first, one-v[i].second);
        int exclude = solve(i+1,v,zero,one);
        
        return dp[i][zero][one] = max(include,exclude);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp , -1 , sizeof(dp));
        vector<pair<int,int>> v;
        
        for(int i=0;i<strs.size();i++){
            v.push_back(calculate(strs[i]));
        }
        
        return solve(0,v,m,n);
    }
};
