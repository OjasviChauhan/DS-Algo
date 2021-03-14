// https://leetcode.com/problems/binary-trees-with-factors/

class Solution {
public:
    int mod = 1000000007;
    int numFactoredBinaryTrees(vector<int> &A) {
        int n = A.size();
        sort(A.begin(),A.end());
        
        long dp[n];
        for(int i=0; i<n; i++){
            dp[i] = 1;
        }
        
        // storing index of all numbers in map
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[A[i]] = i;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                // if A[j] is completely dividing A[i], then it means that
                // A[j] is one factor of A[i], and now we have to find another.
                if(A[i] % A[j] == 0){
                    int k = A[i] / A[j];  // k will be the 2nd factor
                    
                    // but we'll have to check if it is present in arr or not
                    if(mp.find(k) != mp.end())
                        dp[i] = (dp[i] + (dp[j] * dp[mp[k]])) % mod;
                }
            }
        }
        
        long ans = 0;
        for(long i : dp)
            ans += i;
        return ans%mod;
    }
};
