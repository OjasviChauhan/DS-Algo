// https://leetcode.com/problems/maximum-score-from-removing-substrings/

// string s1 and s2 are implemented in the place of stack
class Solution {
public:
    int ans;
    
    void solve(string &s,int x,int y,char a,char b){
        string s1 = "";
        for(int i=0;i<s.size();i++){
            if(!s1.empty() and s1[s1.size()-1] == b and s[i] == a){
                s1.pop_back();
                ans += y;
            }
            else{
                s1.push_back(s[i]);
            }
        }
        
        string s2 = "";
        for(int i=0; i < s1.size(); i++){
            if(!s2.empty() and s2[s2.size()-1] == a and s1[i] == b){
                s2.pop_back();
                ans += x;
            }
            else{
                s2.push_back(s1[i]);
            }
        }
    }
    
    int maximumGain(string s, int x, int y) {
        ans = 0;
        if(s.size() <= 1) return ans;
        
        char a = 'a', b = 'b';
        if(y > x)
            solve(s,x,y,a,b);
        else
            solve(s,y,x,b,a);
        
        return ans;
    }
};
