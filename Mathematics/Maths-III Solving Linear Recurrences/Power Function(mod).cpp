// https://www.interviewbit.com/problems/implement-power-function/

int power(long long x, long long n, int& m) {
     if (n == 0)
        return 1;

    return (n%2 == 0) ? power(x*x % m, n/2, m)%m : x*power(x*x % m, n/2, m)%m;
}

int Solution::pow(int x, int n, int d) {
    if (x == 0)
        return 0;
        
    int res = power(x, n, d);
    if (res < 0)
        return (d + res) % d;
        
    return res;
}
