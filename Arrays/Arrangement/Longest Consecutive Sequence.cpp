// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        
        int best = 0;
        for(int x : s){
            // if x-1 is not present in the set, then it means that 
            // streak is starting from x and from here we can loop till this 
            // streak ends, and then we'll update its best size.
            if(s.find(x-1) == s.end()){
                int y = x+1;
                while(s.count(y)){
                    y++;
                }
                best = max(best,y-x);
            }
        }
        return best;
    }
};

// Time : O(nlogn)
