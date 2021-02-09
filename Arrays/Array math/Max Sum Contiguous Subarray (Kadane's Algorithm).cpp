int Solution::maxSubArray(const vector<int> &A) {
    int sum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<A.size();i++){
        sum += A[i];
        maxSum = max(maxSum,sum);
        if(sum<0) sum=0;
    }
    return maxSum;
}
