// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        
        // 1. Corner Case
        if(tl > sl) return "";
        
        // 2. Freq Maps
        unordered_map<char,int> FS,FT;
        for(int i=0;i<tl;i++){
            char ch = t[i];
            FT[ch]++;
        }
        
        // 3. Sliding Window (Expansion & Contraction + update the minimum length window)
        
        int cnt = 0;    // count of current window size
        int start = 0; // left pointer for shrinking the window
        int end = 0;  // right pointer for expanding the window
        int min_len = INT_MAX;
        int start_idx = -1;
        
        for(end=0;end<sl;end++){
            char ch = s[end];
            FS[ch]++;
            
            // maintain the count of the characters matched (EXPANSION)
            // consider those characters which are already present in 't' and whose
            // freq in FS is less than or equal to that of in FT.
            if(FT[ch] != 0 and FS[ch] <= FT[ch]){
                cnt++;
            }
            
            // if all the characters matched
            if(cnt == tl){
                // start shrinking from left (CONTRACTION)
                char temp = s[start];
                // remove those chars from FS which are not present in 't' or 
                // which have freq more than that of in FT.
                while(FT[temp]==0 or FS[temp]>FT[temp]){

                    FS[temp]--;
                    start++;
                    temp = s[start];
                }
                
                // Window size
                int window_len = end - start + 1;
                if(window_len < min_len){
                    min_len = window_len;
                    start_idx = start;
                }
            }
        }
        
        if(start_idx == -1){
            return "";
        }
        string ans = s.substr(start_idx, min_len);
        return ans;
    }
};
