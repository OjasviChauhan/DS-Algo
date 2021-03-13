// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = min((int)s.size(), k);
        
        for(int i=0; i <= s.size() - n; i++){
            st.insert(s.substr(i, n));
        }
        return st.size() ==  (1 << k);
    }
};
