// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// SOLUTION 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int start=0,end=0;
        unordered_set<char> set;
        int len = 1;
        
        for(end=0;end<s.size();end++){
            if(set.find(s[end]) == set.end()){
                set.insert(s[end]);
            }
            else{
                len = max(len, end-start);
                while(s[start] != s[end]){
                    set.erase(s[start]);
                    start++;
                }
                while(s[end]==s[start] and start<end) start++;
            }
        }
        len = max(len, end-start);
        return len;
    }
};



// SOLUTION 2
class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        if(A.size() == 0) return 0;
        int start = 0, end = 0;
        int len = 0;
        unordered_map<char,int> f;

        for(end = 0; end < A.size(); end++) {
            char ch = A[end] - 'a';
            f[ch]++;
            if(f[ch] > 1) {
                len = max(len, end - start);
                while(f[ch] > 1 and start < end){
                    f[A[start]-'a']--;
                    start++;
                }
            }
        }
        len = max(len, end - start);
        return len;
    }
};
