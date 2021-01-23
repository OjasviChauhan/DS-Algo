/*
Problem : https://leetcode.com/problems/first-missing-positive/

STEP 1: Start traversing the given array.

STEP 2: If number is 0 or negative or greater than array size, just ignore it and move forward.

STEP 3: Otherwise, swap nums[i] with that element in array, whose index is nums[i].
By doing this, we are actually mapping the element of array to its index i.e. nums[i] --> i without using any extra space.

STEP 4: Before doing swaping, Also check that the index from which we have to swap is already not mapped.

STEP 5: After first iteration, start second iteration of traversing, and return the first element which is not mapped with its index.

NOTE: As it might be 0-based indexing, thats why adjustment of indices is important accordingly.

*/


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
