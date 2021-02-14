// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double pow(double x, int n){
        if(n==0) 
            return 1;
        if(n == INT_MIN){
            x = x * x;
            n = n/2;
        }
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
    
    double myPow(double x, int n) {
        return pow(x,n);
    }
};
