// https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    int n = A.size();
    int l=0, r=0, cnt0=0, 
    int L, R;
    int ans = INT_MIN;
    
    vector<int>res;
    int cnt1 = 0;
    for(int i=0;i<n;i++){ 
        if(A[i]=='1') cnt1++;  
    }
    if(cnt1 == n) return res;
    
    for(int i=0;i<n;i++){
        if(A[i]=='0'){ 
            cnt0++; 
            r = i;
        }
        else if(A[i]=='1'){
            cnt0--; 
            if(cnt0 < 0){
                cnt0 = 0;
                l = i+1;
                r = i+1; 
            }
        }
        if(cnt0 > ans){
            ans = cnt0;
            L = l; 
            R = r;
        }
    }
    res.push_back(L+1);
    res.push_back(R+1);
    return res;
}
