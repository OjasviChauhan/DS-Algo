class Solution {
public:    
    int ladderLength(string str, string tar, vector<string>& dict) {
        unordered_set<string> mp;
        for(string &s : dict) mp.insert(s);
        if(mp.find(tar) == mp.end()) return 0;
        
        int cnt = 1;
        queue<string> q;
        q.push(str);
        
        while(!q.empty()) {
            int k = q.size();
            for(int i = 0; i < k; i++) {
                string cur = q.front();
                q.pop();
                
                for(int j = 0; j < cur.size(); j++) {
                    // Retain the original character at current position
                    char orig = cur[j];
                    
                    // trying to make all (26*wordlength) combinations by replacing
                    // the current character with every possible lowercase alphabet.
                    for(char c = 'a'; c <= 'z'; c++) {
                        cur[j] = c;
                        if(cur == tar) return cnt + 1;
                        if(mp.find(cur) != mp.end()){
                            mp.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[j] = orig;
                }
            }
            cnt++;
        }
        return 0;
    }
};
