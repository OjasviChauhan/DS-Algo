// https://leetcode.com/problems/largest-submatrix-with-rearrangements/


// For Explaination
// https://leetcode.com/problems/largest-submatrix-with-rearrangements/discuss/1020682/Java-or-6ms-or-easy-understanding-with-comments-and-images

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] += matrix[i-1][j]; 
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            sort(matrix[i].begin(), matrix[i].end());
            for(int j=1; j<=m; j++){
                ans = max(ans, j * matrix[i][m-j]);
            }
        }
        return ans;
    }
};
