// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

int maxLen(int A[], int n)
{
    int pre=0;
    int len=0;
    unordered_map<int,int> mp;
    
    for(int i=0;i<n;i++){
        pre += A[i];
        if(pre==0){
            len = max(len, i+1);
        }
        if(mp.find(pre) != mp.end()){
            len = max(len, i-mp[pre]);
        }
        else{
            mp[pre] = i;
        }
    }
    return len;
}
