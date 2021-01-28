// https://leetcode.com/problems/missing-number/

/*
The basic idea is to use XOR operation. We all know that a^b^b =a, which means two xor operations 
with the same number will eliminate the number and reveal the original number.
In this solution, I apply XOR operation to both the index and value of the array. 
In a complete array with no missing numbers, the index and value should be perfectly corresponding( nums[index] = index), 
so in a missing array, what left finally is the missing number.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for(int i=0;i<n;i++){
            res = res ^ i ^ nums[i];
        }
        return res;
    }
};
