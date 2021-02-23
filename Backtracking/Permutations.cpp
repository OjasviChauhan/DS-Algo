// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> res;
    void solve(int n,vector<int> &nums,vector<int> &ds,bool used[]){
        if(ds.size() == n){
            res.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i] or i>0 and nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            used[i] = 1;
            solve(n,nums,ds,used);
            ds.pop_back();
            used[i] = 0;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        int n = nums.size();
        bool used[n];
        memset(used,0,sizeof used);
        sort(nums.begin(),nums.end());
        
        solve(n,nums,ds,used);
        return res;
    }
};


// Different Solution

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
