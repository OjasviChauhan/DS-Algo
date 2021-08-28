// https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1#

void frequencyCount(vector<int>& arr,int N, int P)
    { 
        for(int i = 0; i < N; i++){
            arr[i] -= 1;
        }
        
        sort(arr.begin(), arr.end());
        
        int index = N;
    	for(int i = 0 ; i < N ; i++){
    	   if(arr[i] >= N){
    	       arr[i] = 0;
    	       if(index == N){
    	           index = i;
    	       }
    	   }
    	}
        
        for(int i = 0; i < index; i++){
            arr[arr[i] % N] += N; 
        }
        
        for(int i = 0; i < N; i++){
            arr[i] = arr[i] / N;
        }
    }
