// https://leetcode.com/problems/counting-bits/


/* 
The idea being here is that "Any even(parent) number is just a replica of its even/2(child) number,
means they both will have the same number of 1's but in case of Odd(parent) number when you find it's
odd/2(child) which you'll get even, which will always have 0 on both Right Most bits but anyways you
know you need 1 at that place!! Why not just add 1 add there?
*/


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0]=0;
        for(int i=1;i<num+1;i++)
        {
            if(i%2!=0)
                dp[i]=dp[i/2]+1;
            else
                dp[i]=dp[i/2];
        }
        return dp;
    }
};
