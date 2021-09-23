// https://leetcode.com/problems/single-element-in-a-sorted-array/

// Time: O(logN)
// Space: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        int start = 0, end = n - 1;
        int left, right;
        
        while(start < end) {
            int mid = (start + end) / 2;
            
            if(A[mid] > A[(mid+n-1) % n] and A[mid] < A[(mid+1)%n])
                return A[mid];
            
            else if(A[(mid+n-1) % n] == A[mid]){
                left = mid-1-start;
                right = end - mid;
                if(left%2 != 0) end = mid - 2;
                else if(right%2 != 0) start = mid + 1;
            }
            
            else if (A[(mid+1)%n] == A[mid]) {
                left = mid - start;
                right = end - mid - 1;
                if(left%2 != 0) end = mid - 1;
                else if(right%2 != 0) start = mid + 2;
            } 
        }
        return A[end];
    }
};

// Time: O(N)
// Space: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            x = x ^ nums[i];
        }
        return x;
    }
};
