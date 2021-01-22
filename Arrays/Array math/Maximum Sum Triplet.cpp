int getLowValue(int n,set<int> &s){
	auto it = s.lower_bound(n);
	it--;
	return *it;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int ans=0;
    int R[n+1];
    R[n] = 0;
    set<int> s;
    s.insert(INT_MIN);

    for(int i=n-1;i>=0;i--){
        R[i]=max(R[i+1],A[i]);  // creating suffix max array
    }
    for(int i=0;i<n-1;i++){
    	int a = getLowValue(A[i],s);
    	int b = A[i];
    	int c = R[i+1];
    	if(R[i+1] > A[i])
    	    ans = max(ans,a+b+c);
    	s.insert(A[i]);
    }
    return ans;
}
