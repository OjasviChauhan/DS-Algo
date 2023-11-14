/*
Problem Versions
-----------------
1: https://leetcode.com/problems/next-permutation/
2: https://www.interviewbit.com/problems/next-similar-number/
3: https://leetcode.com/problems/next-greater-element-iii/


To understand the intuition behind this algorithm.
https://www.youtube.com/watch?v=LuLCLgMElus&feature=emb_logo


1. Find the largest index k such that nums[k] < nums[k + 1]. 
   If no such index exists, just reverse nums and done.
2. Find the largest index l > k such that nums[k] < nums[l].
3. Swap nums[k] and nums[l].
4. Reverse the sub-array nums[k + 1:].
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j; 
        for(i = nums.size()-2; i >= 0; i--){
            if(nums[i] < nums[i+1]) {
                break;
            }     
        }
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(j = nums.size()-1; j > i; j--){
            if(nums[j] > nums[i]){
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
    }
};
