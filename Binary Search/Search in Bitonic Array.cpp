// https://www.interviewbit.com/problems/search-in-bitonic-array/

int findHighest(vector<int> &A,int n){
    int start = 0;
    int end = n-1;
    
    while(start<=end){
        int mid = start+(end-start)/2;
        if(mid>0 and mid<n-1 and A[mid-1]<A[mid] and A[mid]>A[mid+1]){
            return mid;
        }
        else if(mid>0 and mid<n-1 and A[mid-1]<A[mid] and A[mid]<A[mid+1]){
            start = mid + 1;
        }
        else if(mid>0 and mid<n-1 and A[mid-1]>A[mid] and A[mid]>A[mid+1]){
            end = mid - 1;
        }
    }
    return -1;
}
 
int BSleft(vector<int> &A,int s,int e,int k){
    while(s<=e){
        int mid = s+(e-s)/2;
        if(A[mid]==k) return mid;
        else if(A[mid] < k)
            s = mid + 1;
        else 
            e = mid - 1;
    }
    return -1;
}
int BSright(vector<int> &A,int s,int e,int k){
    while(s<=e){
        int mid = s+(e-s)/2;
        if(A[mid]==k) return mid;
        else if(A[mid] < k)
            e = mid - 1;
        else 
            s = mid + 1;
    }
    return -1;
}
 
int Solution::solve(vector<int> &A, int B) {
    int n = A.size()-1;
    int idx = findHighest(A,n);
    
    int l = BSleft(A,0,idx,B);
    int r = BSright(A,idx+1,n-1,B);
    
    if(l!=-1) return l;
    else if(r!=-1) return r;
    
    return -1; 
}
