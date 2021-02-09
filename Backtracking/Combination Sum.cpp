// https://leetcode.com/problems/combination-sum/

void solve(int i,int tar,vector<int>& A,vector<vector<int>>& ans,vector<int>& ds){
    if(i==A.size()){
        if(tar == 0){
            ans.push_back(ds);
        }
        return;
    }
    
    // pick the element
    if(A[i] <= tar){
        ds.push_back(A[i]);
        solve(i,tar-A[i],A,ans,ds);
        ds.pop_back();
    }
    // NOT pick the element
    solve(i+1,tar,A,ans,ds);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int tar) {
    vector<vector<int>> ans;
    vector<int> ds,a;
    sort(A.begin(),A.end());
    
    a.push_back(A[0]);
    for (auto i = 1; i<A.size(); ++i)
        if (A[i-1] != A[i])
            a.push_back(A[i]);
    
    solve(0,tar,a,ans,ds);
    return ans;
}
