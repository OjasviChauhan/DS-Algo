// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    int resLen = 0;
    int begin = 0;
    void check(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        
        int len = right - left - 1;
        
        if(len > resLen){
            begin = left + 1;
            resLen = len;
        }
    }
    
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        for(int i=0; i<s.size()-1; i++){
            check(s, i, i);
            check(s, i, i+1);
        }
        
        return s.substr(begin, resLen);
    }
};
