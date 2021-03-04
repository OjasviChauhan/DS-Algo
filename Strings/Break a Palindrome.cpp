// https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    bool isPalindrome(string s){
        string t = s;
        reverse(t.begin(),t.end());
        return t == s;
    }
    
    string breakPalindrome(string s) {
        if(s.size() == 1){
            return "";
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i] != 'a'){
                char temp = s[i];
                s[i] = 'a';
                if(isPalindrome(s)){
                    s[i] = temp; // rollback the change
                    s[s.size()-1] = 'b';  // and make last char as b
                    return s;
                }
                else return s;
            }
        }
        // every char of string is a
        s[s.size()-1] = 'b';
        return s;
    }
};
