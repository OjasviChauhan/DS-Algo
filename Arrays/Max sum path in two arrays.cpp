// https://practice.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1#

int max_path_sum(int A[], int B[], int l1, int l2){
    int ans = 0;
    int sum1=0,sum2=0;
    int i=0,j=0;
    while(i<l1 and j<l2){
        if(A[i] > B[j]){
            sum2 += B[j++];
        }
        else if(A[i] < B[j]){
            sum1 += A[i++];
        }
        else{
            ans += A[i] + max(sum1,sum2);
            sum1=0, sum2=0;
            i++;
            j++;
        }
    }
    while(i<l1){
        sum1 += A[i++];
    }
    while(j<l2){
        sum2 += B[j++];
    }
    ans += max(sum1,sum2);
    return ans;
}
