// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    bool isValid(vector<int> &A, int m,int k,int mid){
        int t = 0;
        for(int i=0;i<A.size();i++){
            if(A[i] <= mid){
                t++;
                if(t == k) {
                    m--;
                    t = 0;
                }
            }
            else t = 0;
            if(m <= 0) return true;
        }
        return false;
    }
    
    int minDays(vector<int>& A, int m, int k) {
        int n = A.size();
        if(m*k > n) return -1;
        
        int s = INT_MAX, e = INT_MIN;
        for(int i=0; i<n; i++){
            s = min(s, A[i]);
            e = max(e, A[i]);
        }
        
        int res = -1;
        while(s <= e){
            int mid = (s+e)/2;
            if(isValid(A,m,k,mid)){
                res = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return res;
    }
};
