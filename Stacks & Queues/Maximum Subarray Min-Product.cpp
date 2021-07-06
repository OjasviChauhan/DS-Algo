// https://leetcode.com/problems/maximum-subarray-min-product/

class Solution {
public:
    int mod = 1e9 + 7;
    
    vector<int> NSR(vector<int> &A){
        int n = A.size();
        stack<pair<int,int>> s;
        vector<int> res;
        
        for(int i=n-1; i >= 0; i--){
            if(s.empty()){
                res.push_back(n);
            }
            else if(!s.empty() and A[i] > s.top().first) {
                res.push_back(s.top().second);        
            }
            else if(!s.empty() and A[i] <= s.top().first) {
                while(!s.empty() and s.top().first >= A[i])
                    s.pop();
                if(s.empty())
                    res.push_back(n);
                else
                    res.push_back(s.top().second);
            }
            s.push({A[i], i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    vector<int> NSL(vector<int> &A){
        int n = A.size();
        vector<int> res;
        stack<pair<int,int>> s;
        
        for(int i=0; i < n; i++){
            if(s.empty()){
                res.push_back(-1);
            }
            else if(!s.empty() and A[i] > s.top().first) {
                res.push_back(s.top().second);
            }
            else if(!s.empty() and A[i] <= s.top().first) {
                while(!s.empty() and s.top().first >= A[i])
                    s.pop();
                if(s.empty())
                    res.push_back(-1);
                else
                    res.push_back(s.top().second);
            }
            s.push({A[i], i});
        }
        return res;
    }
    
    int maxSumMinProduct(vector<int>& A) {
        int n = A.size();
        vector<int> r = NSR(A);
        vector<int> l = NSL(A);
        
        long csum[n+1];
        csum[0] = 0;
        
        for(int i=1; i <= n; i++){
            csum[i] = csum[i-1] + A[i-1];
        }
        
        long ans = 0;
        for(int i=0; i < n; i++) {
            int right = r[i];
            int left = l[i] + 1;
            long sum = csum[right] - csum[left];
            
            ans = max(ans, A[i] * sum);
        }
        
        return ans % mod;
    }
};
