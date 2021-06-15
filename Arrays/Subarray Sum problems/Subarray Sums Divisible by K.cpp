class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum=0;
        int freq[K];
        memset(freq,0,sizeof(freq));
        freq[0] = 1;
        
        for(int i=0;i<A.size();i++){
            sum += A[i];
            sum %= K;
            sum = (sum+K)%K;
            freq[sum]++;
        }
        int ans=0;
        for(int i=0;i<K;i++){
            int n = freq[i];
            if(n>=2){
                ans += n*(n-1)/2; 
            } 
        }
        return ans;
    }
};
