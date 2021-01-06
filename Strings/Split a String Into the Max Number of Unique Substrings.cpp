// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

class Solution {
public:
    unordered_set<string> ss;
    int ans=0;
    
    void dfs(string &s,int k){
        if(ss.size()>ans) ans=ss.size();
        if(k>=s.size()) return;
        
        string str="";
        for(int i=k;i<s.size();i++){
            str += s[i];
            
            if(ss.find(str) == ss.end()){
                ss.insert(str);
                dfs(s,i+1);
                ss.erase(str);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        dfs(s,0);
        return ans;
    }
};
