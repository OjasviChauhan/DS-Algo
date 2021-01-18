// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        vector<int> ans;
        
        if(pl > sl) return ans;
        
        unordered_map<char,int> fs,fp;
        for(char c:p){
            fp[c]++;
        }
        
        int start=0,end=0;
        for(end=0;end<sl;end++){
            char ch = s[end];
            fs[ch]++;

            if(fp[ch]==0){
                start = end+1;
                fs.clear();
            }
            else if(fs[ch] > fp[ch]){
                while(fs[s[end]] != fp[s[end]]){
                    fs[s[start]]--;
                    start++;
                }
            }
            
            if(end-start+1 == pl) ans.push_back(start);
        }
        return ans;
    }
};
