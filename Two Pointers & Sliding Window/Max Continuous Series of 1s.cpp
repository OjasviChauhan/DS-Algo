// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

vector<int> Solution::maxone(vector<int> &A, int k) {
    int start = 0, end = 0, len = 0;
    int left = 0, right = 0;
    for(end=0; end < A.size(); end++){
        if(A[end] == 0){
            k--;
        }
        if(k < 0){
            if(end-start > len){
                left = start;
                right = end-1;
                len = end-start;
            }
            while(A[start] == 1) start++;
            start++;
            k++;
            
        }
    }
    if(end-start > len){
        left = start;
        right = end-1;
        len = end-start+1;
    }
 
    vector<int> ans;
    for(int i=left; i <= right; i++){
        ans.push_back(i);
    }
    return ans;
}
