// https://leetcode.com/problems/squares-of-a-sorted-array/

// time: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        if(A.size()==1){
            ans.push_back(A[0]*A[0]);
            return ans;
        }
            
        int i=0;
        while(A[i]<0){
            i++;
            if(i==A.size()) break;
        }
        int j = i-1;
    
        while(j>=0 and i<A.size()){
            if(A[i]*A[i] < A[j]*A[j]){
                ans.push_back(A[i]*A[i]);
                i++;
            }
            else{
                ans.push_back(A[j]*A[j]);
                j--;
            }
        }
        while(i < A.size()){
            ans.push_back(A[i]*A[i]);
            i++;
        }
        while(j >= 0){
            ans.push_back(A[j]*A[j]);
            j--;
        }
        return ans;
    }
};
