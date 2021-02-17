// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start,int tar,vector<int> &A,vector<int> &ds){
        if(tar==0){
            ans.push_back(ds);
            return;
        }
        for(int i=start; i<A.size() && A[i]<=tar; i++){
            if(i>start and A[i]==A[i-1]) continue;
            ds.push_back(A[i]);
            solve(i+1,tar-A[i],A,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,ds);
        return ans;
    }
};
