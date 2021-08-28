/*

1. Traverse the array from start to end.
2. For each element check if the element is less than or equal to zero or not. 
   If negative or zero skip the element as it is freqeuncy.
3. If an element is positive, then check if array[idx] (idx = arr[i] - 1) is positive or not. 
   a. If positive then that means it is the first occurrence in the array and replace arr[i] with arr[idx],
      and then set arr[idx] = -1 as its first frequency.
   b. If arr[idx] is already negative, then it is not the first occurrence, hence increment arr[idx] as arr[idx]–- 
      and set arr[i] = 0.
4. Lastly, traverse the array and make every negative value to positive.

*/

void frequencyCount(vector<int>& arr,int N, int P)
    { 
        int i = 0;
        while(i < N){
            if(arr[i] <= 0) {
                i++;
                continue;
            }
            else{
                int idx = arr[i] - 1;
                if(arr[idx] > 0){
                    arr[i] = arr[idx];
                    arr[idx] = -1;
                }
                else{
                    arr[idx]--;
                    arr[i] = 0;
                    i++;
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(arr[i] < 0)
                arr[i] = -arr[i];
        }
    }
