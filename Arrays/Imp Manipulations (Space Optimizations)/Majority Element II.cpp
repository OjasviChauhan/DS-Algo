// https://leetcode.com/problems/majority-element-ii/

// Here we are maintaining two majority elements by assuming them and if any third minority elements comes
// then we reduce their count by 1. At the end we do second iteration to make sure that they are majority element
// by check their frequency which should be greater than n/3.

// Time : O(n)
// Space : O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int maj1 = -1, maj2 = -1;
        
        for(int ele : nums){
            if(ele == maj1) cnt1++;
            else if(ele == maj2) cnt2++;
            else if(cnt1 == 0){
                maj1 = ele;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                maj2 = ele;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=0; cnt2=0;
        vector<int> ans;
        for(int ele : nums){
            if(ele == maj1) cnt1++;
            else if(ele == maj2) cnt2++;
        } 
        
        if(cnt1 > n/3) ans.push_back(maj1);
        if(cnt2 > n/3) ans.push_back(maj2);
        
        return ans;
    }
};
