// https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    void solve(int i, string s, string ds, vector<string> &ans) {
        if(ds.size() == s.size()) {
            ans.push_back(ds);
            return;
        }
    
        char c = s[i];        
        if(isdigit(c)){
            ds.push_back(c);
            solve(i+1, s, ds, ans);
        }
        else{
            ds.push_back(tolower(c));
            solve(i+1,s,ds,ans);
            ds.pop_back();
                
            ds.push_back(toupper(c));
            solve(i+1, s, ds, ans);
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string ds = "";
        solve(0, s, ds, ans);
        return ans;
    }
};
