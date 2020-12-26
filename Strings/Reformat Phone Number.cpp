// https://leetcode.com/problems/reformat-phone-number/

class Solution {
public:
    void solve(string s,string &S,int n){
        if(n<=3){
            S += '-';
            S += s;
            return;
        }
        if(n==4){
            S += '-';
            S += s.substr(0,2);
            S += '-';
            S += s.substr(2,4);
            return;
        }
        S += '-';
        S += s.substr(0,3);
        solve(s.substr(3,s.size()),S,n-3);
    }

    string reformatNumber(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        s.erase(remove(s.begin(), s.end(), '-'), s.end());
        string S="";
        solve(s,S,s.size());
        return S.substr(1,S.size());
    }
};
