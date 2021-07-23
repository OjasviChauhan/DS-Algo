// https://www.interviewbit.com/old/problems/array-3-pointers/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int ans = INT_MAX;
    while(i < A.size() and j < B.size() and k < C.size()) {
        int mini = min(A[i], min(B[j], C[k]));
        int maxi = max(A[i], max(B[j], C[k]));
        ans = min(ans, maxi - mini);
        if(mini == A[i]) i++;
        else if(mini == B[j]) j++;
        else if(mini == C[k]) k++;
    }
    return ans;
}
