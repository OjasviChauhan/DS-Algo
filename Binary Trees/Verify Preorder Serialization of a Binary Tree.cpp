// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
public:
    bool isValidSerialization(string pre) {
        if (pre.empty()) return false;
        pre += ',';
        
        int n = pre.size();
        int cnt = 1;
        for(int i=0; i < n; i++){
            if (pre[i] != ',') continue;
            cnt--;
            if (cnt < 0) return false;
            if (pre[i-1] != '#') cnt += 2;
        }
        return cnt == 0;
    }
};
