// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 1;
        sort(nums.begin(),nums.end());
        
        int left = 0, right = 0;
        long sum = 0;
        int mx = 1;
        
        while(right < nums.size()){
            if(sum <= k){
                mx = max(mx, right - left + 1);
                right++;
                if(right < nums.size()){
                    sum += (long)(right-left) * (nums[right] - nums[right-1]);
                }
            }
            else{
                sum -= nums[right] - nums[left];
                left++;
            }
        }
        return mx;
    }
};
