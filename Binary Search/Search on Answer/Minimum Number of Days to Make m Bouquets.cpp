// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    bool check(vector<int> &bloomDay, int mid, int m, int k) {
        int flowers = 0, bouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid){
                flowers++;
                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            }
            else flowers = 0;
            if(bouquets >= m) return true;
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m * k > n) return -1;
        
        int start = INT_MAX; 
        int end = 0;
        for(int i = 0; i < n; i++){
            start = min(start, bloomDay[i]);
            end = max(end, bloomDay[i]);
        }
        
        int ans;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(check(bloomDay, mid, m, k)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};
