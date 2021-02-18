// https://leetcode.com/problems/sell-diminishing-valued-colored-balls/

class Solution {
public: 
    vector<int> v;
    
    bool isValid(long val , long order){
        for(auto x : v){
            if(x < val)break;
            order -= (x-val+1);
        }
        if(order > 0)return 0;
        else return 1;
    }
    
    int maxProfit(vector<int>& nums, int order) {
        sort(nums.begin(),nums.end(),greater<int>());
        v = nums;
        long s=0, e = v[0], ans, p = 1e9+7;
        
        while(s <= e){
            long mid = (s + e)/2;
            if(isValid(mid,order)){
                ans=mid;
                s=mid+1;
            }
            else e = mid-1;
        }

        long res=0;
        for(auto x : v){
            if(x <= ans) break;
            order -= (x-ans);
            res += ((long)x*(x+1)/2 - ans*(ans+1)/2) % p;
            res %= p;
        }
        
        if(order > 0) res += ans*order % p;
        res %= p;
        return res;
    }
};
