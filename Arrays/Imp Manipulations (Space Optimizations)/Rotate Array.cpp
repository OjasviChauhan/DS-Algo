// https://leetcode.com/problems/rotate-array/

// Start from one element and keep rotating until we have rotated n different elements.

class Solution {
public:
    void rotate(vector<int>& A, int k) {
        int n = A.size();
        if(n == 1 or k % n == 0) return;
        if ((n == 0) or (k <= 0)) return;
        int curr = 0, start = 0;
        int numToBeRotated = A[0];
        for (int i = 0; i < n; i++) {
            swap(numToBeRotated, A[(curr + k) % n]);
            curr = (curr + k) % n;
            if (curr == start) {
                numToBeRotated = A[++curr];
                ++start;
            }
        }
    }
};
