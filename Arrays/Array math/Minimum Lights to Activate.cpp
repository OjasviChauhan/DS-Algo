// https://www.interviewbit.com/problems/minimum-lights-to-activate/

int solve(vector<int> &A, int B) {    
    int n = A.size(),i=0,cnt=0;   
    if (B == 0) return -1;

    //Start from 0th index
    while(i<n){
    	int idx = -1;
    	//check range [X-B+1, X+B-1] and find rightmost bulb
        for(int j = max(0,i-B+1); j < min(n,i+B); j++){
            if(A[j] == 1){
                idx = j;
            }
        }
        if(idx == -1) return -1;
        cnt++;
        //Start now from index which is outside the current selected bulb
        i = idx + B;
    }
    return cnt;
}
