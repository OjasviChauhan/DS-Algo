// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        
        unordered_map<char,int> FS,FP;
        for(auto c : p){
            FP[c]++;
        }
        
        int start=0,end=0;
        for(end=0; end < s.size(); end++){
            char c = s[end];
            if(FP.count(c)){
                FS[c]++;
                if(FS[c] > FP[c]){
                    while(FS[c] != FP[c]){
                        FS[s[start++]]--;
                    }
                }
                if(end-start+1 == p.size()){
                    ans.push_back(start);
                }
            }
            else{
                FS.clear();
                start = end+1;
            }
        }
        return ans;
    }
};
