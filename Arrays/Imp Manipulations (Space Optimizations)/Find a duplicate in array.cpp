// https://www.interviewbit.com/problems/find-duplicate-in-array/

//approach 1
int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0], fast = A[A[0]];
    while (slow != fast) slow = A[slow], fast = A[A[fast]];
    slow = 0;
    while (slow != fast)  slow = A[slow], fast = A[fast];
    return slow;
}

// approach 2
int Solution::repeatedNumber(const vector<int> &A) {
    vector B(A);
    for(int i=0;i<B.size();i++){
        int idx = abs(B[i])-1;
        if(B[idx] < 0)
            return abs(B[i]);
        B[idx] *= -1;
    }
    return -1;
}
