// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

/*
We use an unordered_map<string, int> counts to record the expected times of each word and another
unordered_map<string, int> seen to record the times we have seen. Then we check for every possible 
position of i. Once we meet an unexpected word or the times of some word is larger than its expected 
times, we stop the check. If we finish the check successfully, push i to the result indexes.
*/


class Solution {
public:
vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> counts;
    for(string word : words)
        counts[word]++;
    
    int n = s.size(), num = words.size(), len = words[0].size();
    vector<int> ans;
    
    for(int i=0; i < n-num*len+1; i++) {
        unordered_map<string, int> seen;
        int j = 0;
        for(; j < num; j++) {
            string word = s.substr(i + j*len, len);
            if(counts.find(word) != counts.end()){
                seen[word]++;
                if (seen[word] > counts[word])
                break;
            }
            else break;
        }
        if(j == num) ans.push_back(i);
    }
    return ans;
    }
};

