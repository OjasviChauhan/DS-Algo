/*
Problem: https://leetcode.com/problems/next-permutation/

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
    	int n = nums.size(), k, l;
    	for(k = n-2; k>=0; k--){
            if(nums[k] < nums[k+1]){
                break;
            }
        }
    	if(k < 0){
    	    reverse(nums.begin(), nums.end());
    	} 
        else{
    	    for(l = n-1; l>k; l--){
                if(nums[l] > nums[k]){
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
}; 
