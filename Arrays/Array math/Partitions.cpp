// https://www.interviewbit.com/problems/partitions/

int Solution::solve(int A, vector<int> &B) {
    int sum = 0;
    for(int i = 0; i < A; i++) sum += B[i];
    if(sum % 3 != 0 ) return 0;
    int sum13rd = sum/3;
    int sum23rd = 2 * sum13rd;
    int currSum = 0;
    int cnt_13rd = 0;
    int count = 0;
    for(int i = 0; i < A - 1; i++) {
        currSum += B[i];
        if(currSum == sum23rd) count += cnt_13rd;
        if(currSum == sum13rd) cnt_13rd++;
    }
    //rumming till only A-1 is important for sum = 0. nd so is order of cnt_13rd++.
    return count;
}
