// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    unordered_map<char,string> mp;
    
    void solve(int start,string digits,string &ds,vector<string> &ans){
        if(ds.size() == digits.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=start; i<digits.size(); i++){
            string s = mp[digits[i]];
            for(char c : s){
                ds.push_back(c);
                solve(i+1,digits,ds,ans);
                ds.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        vector<string> ans;
        int n = digits.size();
        if(n==0) return ans;
        string ds = "";
        solve(0,digits,ds,ans);
        return ans;
    }
};
