// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1#

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        int pre=0;
        int len=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            pre += A[i];
            // when subarray starts from index '0' 
            if(pre==k){
                len = max(len, i+1);
            }
            // make an entry for 'pre' if it is 
            // not present in 'mp' 
            if(mp.find(pre) == mp.end()){
                mp[pre] = i;
            }
            // check if 'pre-k' is present in 'mp' or not 
            if(mp.find(pre-k) != mp.end()){
                len = max(len, i-mp[pre-k]);
            }
        }
        return len;
    } 

};
