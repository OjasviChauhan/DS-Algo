// https://practice.geeksforgeeks.org/problems/count-numbers-in-range5305/1#

/*
The numbers having exactly 3 divisors are square of prime numbers.
for example:  4, 9, 25, 49, ............

Now the problem is reduced to find the number of square of prime numbers
between L and R inclusive. It will be equivalent to number of prime numbers
between square root of L to square root of R inclusive.
*/

class Solution {
public:
    void prime_sieve(bool *p, int n) {
        p[0] = p[1] = false;
        for (long long int i = 2; i * i <= n; i++) {
            if (p[i]) {
                for (long long int j = i * i; j <= n; j += i) {
                    p[j] = false;
                }
            }
        }
    }

    int count3DivNums(long long L, long long R) {
        int l = sqrt(L);
        int r = sqrt(R);
        bool p[r + 1];
        memset(p, true, sizeof p);

        prime_sieve(p, r + 1);
        int ans = 0;
        for (int i = l + 1; i <= r; i++) {
            if (p[i]) ans++;
        }

        return ans;
    }
};
