class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> A, int n ) {
        unordered_map<ll,ll> mp;
        vector<ll> v(n+1);
        v[0] = 0;
        mp[0] = 1;
        for(int i = 1; i <= n; i++){
            v[i] = v[i-1] + A[i-1];
            mp[v[i]]++;
        }
        
        ll ans = 0;
        for(auto &p : mp){
            if(p.second >= 2){
                ans += p.second * (p.second - 1) / 2;
            }
        }
        return ans;
    }   
};
