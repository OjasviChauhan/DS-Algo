class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start){
        vector<vector<int>> res;
        int lo = start, hi = nums.size()-1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target || (lo>start && nums[lo] == nums[lo-1]))
                ++lo;
            else if (sum>target || (hi < nums.size()-1 && nums[hi] == nums[hi+1]))
                --hi;
            else
                res.push_back({ nums[lo++], nums[hi--] });
        }
        return res;
    }

    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k){
        vector<vector<int>> res;
        
        // Base Cases
        if (start == nums.size() || nums[start]*k > target || target > nums.back()*k)
            return res;
        if (k == 2)
            return twoSum(nums, target, start);
        
        // Recursive case
        for (int i = start; i < nums.size(); ++i)
            if (i == start || nums[i - 1] != nums[i])
                for (auto &set : kSum(nums, target-nums[i], i+1, k-1)) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    for(int &x : set) temp.push_back(x);
                    res.push_back(temp);
                }
        
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
};
