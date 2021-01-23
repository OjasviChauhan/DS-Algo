// https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    int l=1, r=B;
    vector<int> ans;
    if(A[0]=='D') 
        ans.push_back(r--);
    else 
        ans.push_back(l++);
    
    for(int i=0;i<A.size()-1;i++){
        if(A[i+1]=='D')
            ans.push_back(r--);
        else
            ans.push_back(l++);
    }
    ans.push_back(l);
    return ans;
}
