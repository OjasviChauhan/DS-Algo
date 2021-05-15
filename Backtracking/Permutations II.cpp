// https://leetcode.com/problems/permutations-ii/solution/

class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums, vector<int> &ds, map<int,int> &cnt){
        if(ds.size() == nums.size()){
            res.push_back(ds);
            return;
        }
        
        for (auto &p : cnt){
            if (p.second == 0) continue;
            p.second--;
            ds.push_back(p.first);
            solve(nums, ds, cnt);
            ds.pop_back();
            p.second++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        map<int,int> cnt;
        for(int i : nums){
            cnt[i]++;
        }
        vector<int> ds;
        
        solve(nums, ds, cnt);
        return res;
    }
};


// Another Solution

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
