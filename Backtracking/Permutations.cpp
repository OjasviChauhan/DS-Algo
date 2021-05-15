// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums, vector<int> &ds, bool used[]){
        if(ds.size() == nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0; i < nums.size(); i++){
            if(!used[i]){
                ds.push_back(nums[i]);
                used[i] = 1;
                solve(nums,ds,used);
                ds.pop_back();
                used[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        bool used[nums.size()];
        memset(used,0,sizeof used);
        
        solve(nums,ds,used);
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
