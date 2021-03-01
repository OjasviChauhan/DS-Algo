// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        int mp[26] = {0};
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(mp[i] > 0) ans += mp[i];
        }
        return ans;
    }
};
