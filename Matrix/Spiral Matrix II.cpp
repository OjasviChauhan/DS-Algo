// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> A(n,vector<int>(n));
        int k = 0;
        int x = 1;
        
        while(k <= n/2){
            // going right ---->
            for(int j=k; j<n-k; j++){
                A[k][j] = x++;
            }
            
            // going down
            for(int i=k+1; i<n-k; i++){
                A[i][n-1-k] = x++;
            }
            
            // going left <----
            for(int j=n-2-k; j>=k; j--){
                A[n-k-1][j] = x++;
            }
            
            // going up
            for(int i=n-2-k; i>k; i--){
                A[i][k] = x++;
            }
            k++;
        }
        return A;
    }
};
