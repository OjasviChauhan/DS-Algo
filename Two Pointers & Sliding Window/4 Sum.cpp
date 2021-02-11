// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i+3<n; i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1; j+2<n; j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int l=j+1, r=n-1;
                
                while(l<r){
                    if(l>j+1 and nums[l]==nums[l-1]){
                        l++;
                        continue;
                    }
                    if(r<n-1 and nums[r]==nums[r+1]){
                        r--;
                        continue;
                    }
                    
                    int sum = nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum > target) r--;
                    else if(sum < target) l++;
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
