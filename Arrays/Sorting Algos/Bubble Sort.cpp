#include <iostream>
#include <vector>
using namespace std;
 
void BubbleSort (vector<int> &arr, int n) {
   for (int i = 0; i < n - 1; ++i) { 
      bool swapped = false;
      for (int j = 0; j < n - i - 1; ++j) {
         if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j + 1]);
            swapped = true;
         }
      }
      if(!swapped) break;
   } 
} 
 
int main() {
   vector<int> arr = {5, 6, 2, 6, 9, 0, -1};
   int n = 7;
   BubbleSort(arr, n);
  
   for (i = 0; i < n; i++)
        Cout << arr[i] << “ “;
 
   return 0;
}
