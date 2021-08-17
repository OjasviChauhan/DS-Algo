// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curEnd = 0, curFarthest = 0;
        
        for(int i = 0; i < n-1; i++) {
            curFarthest = max(curFarthest, i + nums[i]);
            if(i == curEnd){
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};
