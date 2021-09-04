// https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};

// ....................... OR ..............................

class Solution {
public:
    int kadaneMax(vector<int> &A){
        int max_sum = INT_MIN, sum = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            max_sum = max(max_sum, sum);
            if(sum < 0) sum = 0;
        }
        return max_sum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int nonCircularSum = kadaneMax(nums);
        
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
            nums[i] = -nums[i];
        }
        
        int minSum = kadaneMax(nums);
        int circularSum = totalSum + minSum;
        if(circularSum == 0) return nonCircularSum;
        return max(nonCircularSum, circularSum);
    }
};
