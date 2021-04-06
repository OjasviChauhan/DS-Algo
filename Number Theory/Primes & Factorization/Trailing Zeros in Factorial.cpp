// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

/*

Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....

*/

int Solution::trailingZeroes(int n) {
    int count = 0; 
    for (int i=5; n/i >= 1; i*=5) 
        count += n/i; 
  
    return count; 
}
