#include <iostream>
using namespace std;

/*
Binary exponentiation (also known as exponentiation by squaring) 
is a trick which allows to calculate an using only O(logn) 
multiplications (instead of O(n) multiplications required 
by the naive approach).
*/

long long powRecursive(long long x, long long n) {
    if (n == 0)
        return 1;
    long long res = powRecursive(x, n / 2);
    if (n % 2 == 0)
        return res * res;
    else
        return res * res * x;
}

/*
The second approach accomplishes the same task without recursion. 
It computes all the powers in a loop, and multiplies the ones with 
the corresponding set bit in n. Although the complexity of both 
approaches is identical, this approach will be faster in practice
since we have the overhead of the recursive calls.
*/

long long powIterative(long long x, long long n){
    long long res = 1;
    while(n > 0){
        if(n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

int main() {

    cout << powRecursive(2,5) << endl;
    cout << powIterative(2,5) << endl;
    
}
