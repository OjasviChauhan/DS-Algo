#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int l, int r) {
    int pivot = A[l];
    int i = l;
    int j = r;

    while (i < j) {
        while (A[i] <= pivot) i++;
        while (A[j] > pivot) j--;
        if (i < j) swap(A[i], A[j]);
    }
    swap(A[j], A[l]);
    return j;
}

void quickSort(int A[], int l, int r) {
    if (l >= r) return;
    int pivot = partition(A, l, r);
    quickSort(A, l, pivot - 1);
    quickSort(A, pivot + 1, r);
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
    quickSort(A, l, r);
 
    for(int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    
    return 0;
}
