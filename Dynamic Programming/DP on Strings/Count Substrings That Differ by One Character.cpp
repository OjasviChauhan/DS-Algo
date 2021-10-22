// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

class Solution {
public:
    int solve(string s, string t, int i, int j) {
        int res = 0, pre = 0, cur = 0;
        int n = s.size(), m = t.size();
        while (i < n and j < m) {
            cur++;
            if (s[i++] != t[j++]){
                pre = cur; 
                cur = 0;
            }
            res += pre;
        }
        return res;
    }
    
    int countSubstrings(string s, string t) {
        int res = 0 ;
        for (int i = 0; i < s.size(); i++)
            res += solve(s, t, i, 0);
        cout << res;
        for (int j = 1; j < t.size(); j++)
            res += solve(s, t, 0, j);
        return res;
    }
};
