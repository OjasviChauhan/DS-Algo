// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    long nCr(long n, long k) { 
        long long res = 1; 
        if (k > n - k) 
            k = n - k; 
        for (long i = 0; i < k; ++i) { 
            res *= (n - i); 
            res /= (i + 1); 
        } 
        return res; 
    }
    
    long numTrees(long n) {
        return nCr(2*n, n)/(n+1);
    }
};
