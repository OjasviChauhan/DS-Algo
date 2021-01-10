// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &c,vector<int> &v,int remain,int start){
        if(remain<0){
            return;
        }
        else if(remain==0){
            ans.push_back(v);
        }
        else{
            for(int i=start;i<c.size();i++){
                v.push_back(c[i]);
                solve(c,v,remain-c[i],i);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        solve(candidates,v,target,0);
        return ans;
    }
};
