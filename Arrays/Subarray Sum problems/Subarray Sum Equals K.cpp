class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Sum => Frequency
        unordered_map<int,int> mp;
        int count = 0;
        int sum = 0;
        
        // Sum of 0 shows up once.
        mp[sum] = 1;
        for(int num : nums){
            sum += num;
    
            if(mp.find(sum-k) != mp.end())
                count += mp[sum-k];
            
            mp[sum]++;
        }
        
        return count;
    }
};
