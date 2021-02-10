// FASTEST using 2 pointers

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> ans;
        sort(A.begin(),A.end());

        for(int i=0;i<n-2;i++){
            if(i>0 && A[i]==A[i-1] )continue;
            int j = i+1, k = n-1;
            while(j<k){
                int sum = A[i]+A[j]+A[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    ans.push_back({A[i],A[j],A[k]});
                    while(j+1<k && A[j]==A[j+1]) j++;
                    while(j<k-1 && A[k]==A[k-1]) k--;
                    j++; k--;
                }
            }
        }
        return ans;
    }
};


// Using 2 pointers in O(N*N) time, slightly slow than upper one

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> ans;
    int n=A.size();
    sort(A.begin(),A.end());
    
    for(int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;
        
        if (i>0 && A[i]==A[i-1])    // pass duplicates for i
            continue;
            
        while(j<k){
            if (j>i+1 && A[j]==A[j-1]){    // pass duplicates for j
                j++;
                continue;
            }

            if (k<n-1 && A[k]==A[k+1]){    // pass duplicates for k
                k--;
                continue;
            }
            
            long long int sum = (long long int)A[i] + (long long int)A[j] + (long long int)A[k];
            if(sum==0){
                ans.push_back({A[i],A[j],A[k]});
                j++;
                k--;
            }
            else if(sum<0){
                j++;
            }
            else
                k--;
        }
    }
    return ans;
}



// Using sets in O(N*N*Log(S)) time and Log(S) space, VERY SLOW !!

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> store;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while(left < right)
            {
                if(nums[left] + nums[right] == target)
                {
                    store.insert({-target, nums[left], nums[right]});
                    right--;
                    left++;
                }
                else if(nums[left] + nums[right] > target)
                    right--;
                else
                    left++;
            }
        }
        
        for(auto i : store)
        {
            res.push_back(i);
        }
        
        return res;
    }
};
