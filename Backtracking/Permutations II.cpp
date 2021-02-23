// https://leetcode.com/problems/permutations-ii/solution/

class Solution {
public:
    vector<vector<int>> res;
    void solve(int n,vector<int> &nums,vector<int> &ds,bool used[]){
        if(ds.size() == n){
            res.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i] or i>0 and nums[i]==nums[i-1] and !used[i-1]) continue;
            ds.push_back(nums[i]);
            used[i] = 1;
            solve(n,nums,ds,used);
            ds.pop_back();
            used[i] = 0;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ds;
        int n = nums.size();
        bool used[n];
        memset(used,0,sizeof used);
        sort(nums.begin(),nums.end());
        
        solve(n,nums,ds,used);
        return res;
    }
};
