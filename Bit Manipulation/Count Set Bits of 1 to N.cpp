// https://www.interviewbit.com/problems/count-total-set-bits/

#define m 1000000007
long maxPowerofTwo(int n){
    int x=0;
    while((1<<x) <= n){
        x++;
    }
    return x-1;
}

int Solution::solve(int n) {
    if(n==0){
        return 0;
    }
    long x = maxPowerofTwo(n);
    long bitsUpto2Rx = (x*(1<<x-1)%m)%m;
    long msbits = (n - (1<<x)%m + 1);
    long rest = (n - (1<<x)%m);
    int ans = (bitsUpto2Rx + msbits + solve(rest)%m)%m;
    return ans;
}
