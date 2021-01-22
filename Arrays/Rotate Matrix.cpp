
// https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    int k=1, r=0, d=0, l=n-1, u=n-1;
        
    while(k <= n/2){
        while(r<n-k and d<n-k and l>=k and u>=k){
            swap(A[k-1][r],A[d][n-k]);
            swap(A[k-1][r],A[n-k][l]);
            swap(A[k-1][r],A[u][k-1]);
            r++;
            d++;
            l--;
            u--;
        }
        r = k;
        d = k;
        l = n-1-k;
        u = n-1-k;
        k++;
    }
}
