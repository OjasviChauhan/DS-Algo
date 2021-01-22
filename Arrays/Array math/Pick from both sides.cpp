// https://www.interviewbit.com/problems/pick-from-both-sides/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> pre(n+1,0), suf(n+1,0);

    for(int i=1;i<=A.size();i++){
        pre[i] = pre[i-1] + A[i-1];
        suf[n-i] = suf[n-i+1] + A[n-i];
    }

    int maxSum = INT_MIN;
    for(int i=0;i<=B;i++){
        maxSum = max(maxSum, pre[i]+suf[n-(B-i)]);
    }
    return maxSum;
}
