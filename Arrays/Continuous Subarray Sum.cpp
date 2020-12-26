// https://leetcode.com/problems/continuous-subarray-sum/
// O(N*N)
// O(N)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1) return 0;
        
        int sum[n+1];
        memset(sum,0,sizeof(sum));
        
        for(int i=0;i<n;i++){
            sum[i+1] = sum[i]+nums[i]; 
        }
        
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int diff = abs(sum[j]-sum[i-1]);
                if(diff==0)
                    return 1;
                else if(k!=0 and diff % k == 0 and diff>=k)
                    return 1;
            }
        }
        return 0;
    }
};

// O(N) time
// O(k) space

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0,rem=0;
        unordered_set<int> s;

        for(int i=0;i<n;i++){
            sum += nums[i];
            if(k!=0){
                sum %= k;
            }
            if(s.count(sum)){
                return 1;
            }
            else{
                s.insert(rem);
                rem = sum;
            }
        }
        return 0;
    }
};
