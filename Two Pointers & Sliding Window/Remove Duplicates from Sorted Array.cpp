// TWO POINTERS
// O(n) time
// O(1) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};


// USING SETS
// O(Nlogn) time
// O(n) space
int Solution::removeDuplicates(vector<int> &vec) {
    unordered_set<int> s;
    for (int i : vec)
        s.insert(i);
    vec.assign( s.begin(), s.end() );
    sort( vec.begin(), vec.end() );
    return vec.size();
}
