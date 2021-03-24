// https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        unordered_map<int,long> mp;
        for(int i:A) mp[i]++;
        
        sort(A.begin(),A.end());
        int i;
        long cnt = 0;
        for(i=0; i < n-2; i++){
            int j = i+1, k = n-1;
            while(j < k){
                int sum = A[i] + A[j] + A[k];
                if(sum > target) {
                    while(k and A[k] == A[k-1]) k--;
                    k--;
                }
                else if(sum < target) {
                    while(j < n-1 and A[j] == A[j+1]) j++;
                    j++;
                }
                else{
                    // when i != j != k
                    if(A[i] != A[j] and A[j] != A[k] and A[i] != A[k])
                        cnt += (mp[A[i]] * mp[A[j]] * mp[A[k]]);
                    
                    // when i == j != k
                    else if(A[i] == A[j] and A[j] != A[k])
                        cnt += (mp[A[i]] * (mp[A[j]]-1) * mp[A[k]])/2;
                    
                    // when i != j == k
                    else if(A[i] != A[j] and A[j] == A[k])
                        cnt += (mp[A[i]] * mp[A[j]] * (mp[A[k]]-1))/2;
                    
                    // when i == j == k
                    else if(A[i] == A[j] and A[j] == A[k])
                        cnt += (mp[A[i]] * (mp[A[j]]-1) * (mp[A[k]]-2))/6;
                    
                    while(k and A[k] == A[k-1]) k--;
                    k--;
                    while(j < n-1 and A[j] == A[j+1]) j++;
                    j++;
                }
            }
            while(i<n-3 and A[i]==A[i+1]) i++;
        }
        
        return cnt % 1000000007;
    }
};
