// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

bool isValid(int limit,int n,int m,int *A){
    int k=1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += A[i];
        if(sum > limit){
            k++;
            sum = A[i];
        }
        if(k>m) return false;
    }
    return true;
}


int findPages(int *A, int n, int m) {
    int sum=0;
    int maxElement = INT_MIN;
    for(int i=0;i<n;i++){
        sum += A[i];
        maxElement = max(maxElement,A[i]);
    }
    int s = maxElement;
    int e = sum;
    
    int result = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(isValid(mid,n,m,A)){
            result = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return result;
}
