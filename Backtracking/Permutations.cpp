// https://leetcode.com/problems/permutations/

void solve(vector<int> &A,int n,vector<vector<int>> &ans,vector<int> &ds){
    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(find(ds.begin(),ds.end(),A[i]) != ds.end()) continue;
        ds.push_back(A[i]);
        solve(A,n,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> ans;
    vector<int> ds;
    solve(A,n,ans,ds);
    return ans;
}
