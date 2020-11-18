// https://leetcode.com/problems/single-number/

/*

1. If we take XOR of zero and some bit, it will return that bit
    a)   a ⊕ 0 = a
    
2. If we take XOR of two same bits, it will return 0
    b)   a ⊕ a = 0
    
3. a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b
So we can XOR all bits together to find the unique number.

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            ans ^= x;
        }
        return ans;
    }
};

// Time: O(N)
// Space: O(1)
