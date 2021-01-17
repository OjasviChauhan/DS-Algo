// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> m1;
        for(int i=0;i<words.size();i++){
            m1[words[i]]++;
        }
        
        vector<int> ans;
        int ws = words[0].size();
        int l1 = ws * words.size();
        
        for(int i=0; i+l1 <= s.size(); i++){
            string temp = s.substr(i, l1);
            unordered_map<string,int> m2;
            
            int k=0;
            while(k+ws <= temp.size()){
                m2[temp.substr(k,ws)]++;
                k += ws;
            }
            
            if(m1==m2)
                ans.push_back(i);
        }
        return ans;
    }
};
