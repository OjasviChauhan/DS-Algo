#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int B[r - l + 1];

    while (i <= mid and j <= r) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++, k++;
        }
        else {
            B[k] = A[j];
            j++, k++;
        }
    }
    while (i <= mid) {
        B[k] = A[i];
        i++, k++;
    }
    while (j <= r) {
        B[k] = A[j];
        j++, k++;
    }

    for (int k = l; k <= r; k++) {
        A[k] = B[k];
    }
}

void mergeSort(int A[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(A, l, mid);
    mergeSort(A, mid + 1, r);
    merge(A, l, mid, r);
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int l = 0;
    int r = n - 1;
    mergeSort(A, l, r);
 
    for(int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    
    return 0;
}
