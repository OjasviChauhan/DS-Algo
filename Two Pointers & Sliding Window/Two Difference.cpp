// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

bool findPair(int A[], int size, int n){
    sort(A, A + size);
    int i = 0, j = 1;
    while(i < size and j < size){
        int diff = A[j] - A[i];
        if(diff == n) return true;
        else if(diff > n) i++;
        else j++;
    }
    return false;
}
