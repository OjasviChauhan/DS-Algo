// https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int N = sizeof(n) * 8;
        
        int ans = 0;
        for(int i = 0; i < N; i++) {
            if(n & (1 << i)){
                ans |= (1 << (N-i-1));
            }    
        }
        return ans;
    }
};
