// https://leetcode.com/problems/number-of-matching-subsequences/

/*

First, we store all characters' positions of input.
For example: input = "abacbca" ---> POS = ['a', 'b', 'c'] = [ [0,2,6], [1,4], [3,5] ]

Second, while iterating words, for each character of each word, we check if we 
can choose a position from POS, and the position must follow an increasing order.
For example: word = "acb"
'a' we choose 0
'c' we choose 3
'b' we choose 4
[0,3,4] is an increasing order, so "acb" is a subsequence of our input.

Third, we store the position of current iterating character in a variable cur. 
The next iteration, we will chose the position so that it's value > cur by 
using Binary Search

*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        vector<vector<int>> pos(26);
        for(int i=0;i<s.size();i++){
            pos[s[i]-'a'].push_back(i);
        }
        
        for(string &w : words){
            int cur = -1;
            bool flag = false;
            for(int i = 0; i < w.length(); i++){
                int c = w[i]-'a';
                auto p = upper_bound(pos[c].begin(), pos[c].end(), cur);
                if(p == pos[c].end()) {
                    flag = true;
                    break;
                }
                cur = *p;
            }
            if(!flag) res++;
        }
        return res;
    }
};
