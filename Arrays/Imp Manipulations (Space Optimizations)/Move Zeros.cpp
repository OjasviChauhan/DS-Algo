// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& A) {
        int n = A.size();
        
        int zero = 0;
        while(zero < n and A[zero] != 0) zero++;
        if(zero == n) return;
        
        int nonZero = zero + 1;
        while(nonZero < n and A[nonZero] == 0) nonZero++;

        while(nonZero < n and zero < n){
            swap(A[zero], A[nonZero]);
            while(zero < n and A[zero] != 0) zero++;
            while(nonZero < n and A[nonZero] == 0) nonZero++;
        }
    }
};
