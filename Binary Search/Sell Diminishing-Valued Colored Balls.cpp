// https://leetcode.com/problems/sell-diminishing-valued-colored-balls/

#define mod 1000000007
class Solution {
public:
    map<int, int, greater<>> mp;

    bool isValid(int M, int k){
        for(auto &[i, cnt] : mp){
            if(i <= M) break;
            k -= (long)cnt * (i - M);
            if(k <= 0) return true; 
        }
        return k <= 0;
    }
    
    int maxProfit(vector<int> &A, int orders) {
        long ans = 0, L = 0, R = *max_element(begin(A), end(A));
        for (int i : A) mp[i]++;
        
        while(L <= R){
            long M = (L + R) / 2;
            if (isValid(M, orders)) L = M + 1;
            else R = M - 1;
        }
        
        for(auto &[i, cnt] : mp){
            if(i <= L) break;
            orders -= cnt * (i - L);
            ans = (ans + (i+L+1)*(i-L)/2 % mod * cnt % mod) % mod;
        }
        if(orders > 0) ans = (ans + L*orders % mod) % mod;
        
        return ans;
    }
};
