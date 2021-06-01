// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

class Solution{   
public:
    int median(vector<vector<int>> &A, int r, int c){
        int h = 0, l = 2001;
        for(int i=0;i<r;i++){
            l = min(l, A[i][0]);
            h = max(h, A[i][c-1]);
        }
        
        int n = (r*c+1)/2;
        while(l < h){
            int mid = (l+h)/2;
            int cnt = 0;
            for(int i = 0; i < r; i++){
                cnt += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
            }
            if(cnt < n) l = mid+1;
            else h = mid;
        }
        return l;
    }
};
