// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        vector<int> ans;
        int n = A.size();
        int m = A[0].size();
        int k=0;
        
        while(k <= n/2){
            // going right ---->
            for(int j=k;j<m-k;j++){
                ans.push_back(A[k][j]);
            }
            if(ans.size() == m*n) break;
            
            // going down 
            for(int i=k+1;i<n-k;i++){
                ans.push_back(A[i][m-1-k]);
            }
            if(ans.size() == m*n) break;
            
            // going left <----
            for(int j=m-2-k;j>=k;j--){
                ans.push_back(A[n-1-k][j]);          
            }
            if(ans.size() == m*n) break;
            
            // going up
            for(int i=n-2-k;i>k;i--){
                ans.push_back(A[i][k]);
            }
            if(ans.size() == m*n) break;
            k++;
        }
        return ans;
    }
};
