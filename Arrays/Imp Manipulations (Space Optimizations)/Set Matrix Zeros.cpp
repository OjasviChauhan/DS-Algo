// https://leetcode.com/problems/set-matrix-zeroes/

// Space : O(1)
// Time : O(m*n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        int R = A.size();
        int C = A[0].size();
        bool isCol = false;
        
        for(int i=0; i<R; i++){
            // checking if first column contains zero at any point
            if(A[i][0] == 0) {
                isCol = true;
            }
            
            for(int j=1; j<C; j++){
                // If an element is zero, we set the first element of
                // the corresponding row and column to 0
                if(A[i][j] == 0){
                    A[0][j] = 0;
                    A[i][0] = 0;
                }
            }
        }
        
        // Iterate over the array once again and using the first row 
        // and first column, update the elements.
        for(int i=1; i<R; i++){
            for(int j=1; j<C; j++){
                if(A[i][0]==0 || A[0][j]==0){
                    A[i][j] = 0;
                }
            }
        }
        
        // See if the first row needs to be set to zero as well
        if(A[0][0] == 0){
            for(int j=0; j<C; j++){
                A[0][j] = 0;
            }
        }
        
        // See if the first column needs to be set to zero as well
        if(isCol){
            for(int i=0; i<R; i++){
                A[i][0] = 0;
            }
        }  
    }
};
