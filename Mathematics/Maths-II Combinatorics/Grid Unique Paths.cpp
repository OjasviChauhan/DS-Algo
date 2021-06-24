// https://www.interviewbit.com/problems/grid-unique-paths/

/*
Just find the total permutations by using the formula:

                  (R+C)! 
                  ------
                  R! * C!
 */     
      
int Solution::uniquePaths(int A, int B) {
    if(A == 1 or B == 1) return 1;
    A--, B--;
    long res = 1;
    if(A > B) swap(A,B);
    for(int i = 0; i < A; i++){
        res *= (A+B-i);
        res /= i+1;
    }
    return res;
}
