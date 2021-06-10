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


// if question says that there is no gurantee for presence of majority element.
// And if not present then you have to return -1. In that case, first we'll have
// to check for possible candidate for majority element and then confirm it by
// checking its frequency i.e it should be greater than size/2.

int findCandidate(vector<int> a, int n){
    int maj = a[0], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (maj == a[i]) cnt++;
        else cnt--;
        if (cnt == 0) {
            maj = a[i];
            cnt = 1;
        }
    }
    return maj;
}
    
bool isMajority(vector<int> a, int n, int cand) {
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == cand)
            cnt++;
    }
    if (cnt > n / 2) return 1;
    else return 0;
}
 
int Solution::majorityElement(const vector<int> &a) {
    int n = a.size();
    int cand = findCandidate(a, n);
    if (isMajority(a, n, cand))
        return cand;
    else
        return -1;
}
