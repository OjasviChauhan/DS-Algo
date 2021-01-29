// https://leetcode.com/problems/majority-element/

/*
Time : O(n)
Space: O(1)
MOORE'S VOTING ALGORITHM
-------------------------

Essentially, what Boyer-Moore does is look for a suffix sufsuf of nums where suf[0]suf[0] is the majority element in that suffix. 
To do this, we maintain a count, which is incremented whenever we see an instance of our current candidate for majority element and 
decremented whenever we see anything else. Whenever count equals 0, we effectively forget about everything in nums up to the 
current index and consider the current number as the candidate for majority element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int maj = nums[0];
        for(int i=1;i<nums.size();i++){
            if(count==0){
                maj = nums[i];
                count = 0;
            }
            count += (nums[i] == maj) ? 1 : -1;
        }
        return maj;
    }
};
