// https://www.interviewbit.com/problems/sort-array-with-squares/

vector<int> Solution::solve(vector<int> &A){
    int i=0;
    while(A[i]<0){i++;}
    int j = i-1;
    
    vector<int> ans;
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
