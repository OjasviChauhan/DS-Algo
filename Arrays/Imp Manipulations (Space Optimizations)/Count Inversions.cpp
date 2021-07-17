// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    int arr[100000]; //used to store the result using indices
    
    void merge(vector<pair<int,int>>& A,int low,int mid,int high){
        int i = low;
        int j = mid + 1;
        int count = 0; //the number of elements larger in the A from low to mid
        vector<pair<int,int>> B(high-low+1);
        int k = 0;
        while(i <= mid && j <= high) {
            if(A[i].first <= A[j].first) {
                arr[A[i].second] += count; //add the number of larger elements
                B[k++] = A[i++];
            }
            else{
                count++;    // A[i] > A[j] and i < j
                B[k++] = A[j++];
            }
        }
        while(i <= mid) {
            arr[A[i].second] += count; //add the number of larger elements
            B[k++] = A[i++]; 
        }
        while(j <= high) {
            B[k++] = A[j++];
        }

        for(int i = 0; i < k; i++) {
            A[low++] = B[i];
        }
    }
    
    void mergeSort(vector<pair<int,int>>& A,int low,int high) {
        int mid = (low + high)/2;
        if(low < high) {
            mergeSort(A, low, mid);
            mergeSort(A, mid + 1, high);
            merge(A, low, mid , high);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        //we store the vector of A
        //why we use pair , since we need to know the 
        //index of the element in the original array 
        vector<pair<int,int>> A;
        for(int i=0;i<nums.size();i++) {
            A.push_back({nums[i],i});
        }
        
        mergeSort(A,0,nums.size()-1);
        vector<int> res(nums.size());
        
        for(int i=0;i<nums.size();i++) {
            res[i] = arr[i];
        }
        return res;
    }
};
