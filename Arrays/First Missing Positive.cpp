class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;){
            if(nums[i]<=0 or nums[i]>n) i++;   
            else{ 
                int idx = nums[i]-1;
                if(nums[i]-i != 1 and nums[idx]-idx != 1)
                    swap(nums[i],nums[idx]);
                else i++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]-i != 1){
                return i+1;
            }
        }
        return n+1;
    }
};
