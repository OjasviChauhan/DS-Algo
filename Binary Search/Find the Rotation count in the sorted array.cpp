class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int start = 0;
	    int end = n-1;
	    while(start<=end){
	        int mid = (start + end)/2;
	        int nextToMid = (mid+1)%n;
	        int prevToMid = (mid+n-1)%n;
	        
	        if(arr[mid]<arr[prevToMid] && arr[mid]<arr[nextToMid]){
	            return mid;
	        }
	        else if(arr[start] <= arr[mid] && arr[mid] <= arr[end]){
	            return start;
	        }
	        else if(arr[start] <= arr[mid]){
	            start = mid+1;
	        }
	        else if (arr[mid] <= arr[end]){
	            end = mid-1;
	        }
	    }
	}
};
