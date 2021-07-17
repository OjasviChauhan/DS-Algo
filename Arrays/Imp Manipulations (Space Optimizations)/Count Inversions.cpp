// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    int arr[100000]; //used to store the result using indices
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
    void mergeSort(vector<pair<int,int>>& A,int low,int high) {
        int mid = (low + high)/2;
        if(low < high) {
            mergeSort(A, low, mid);
            mergeSort(A, mid + 1, high);
            merge(A, low, mid , high);
        }
    }
    
    void merge(vector<pair<int,int>>& A,int low,int mid,int high){
        //mid is the starting element for the second array
        int i = low;
        int j = mid + 1;
        int count = 0; //the number of elements smaller in the arr from mid to high
        vector<pair<int,int>> B(high-low+1);
        int k = 0;
        while(i <= mid && j <= high) {
            if(A[i].first <= A[j].first) {
                arr[A[i].second] += count; //add the number of smaller elements
                B[k++] = A[i++];
            }
            else{
                count++;
                B[k++] = A[j++];
            }
        }
        //add the remaining first array element if left any
        while(i <= mid) {
            arr[A[i].second] += count; //add the number of smaller elements
            B[k++] = A[i++]; 
        }
        //add the remaining second array elements if left any
        while(j <= high) {
            B[k++] = A[j++];
        }
        //change the A to make it in sorted order 
        for(int i = 0; i < k; i++) {
            A[low++] = B[i];
        }
    }
};
