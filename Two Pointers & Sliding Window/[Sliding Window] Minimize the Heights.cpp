// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

class Solution {
  public:
    int getMinDiff(int A[], int n, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            if(A[i] - k >= 0)
                v.push_back({A[i]-k, i});
            v.push_back({A[i]+k, i});
        }
        sort(v.begin(), v.end());
        
        vector<int> vis(n,0);
        int cnt = 0;
        
        // sliding window starts....
        int left = 0, right = 0;
        //INITIAL EXPANSION...
        while(cnt < n and right < v.size()){
            int idx = v[right].second;
            if(vis[idx] == 0) 
                cnt++;
            vis[idx]++;
            right++;
        }
        
        int ans = v[right-1].first - v[left].first;
        // MOVING WINDOW...
        while(right < v.size()){
            int idx = v[left].second;
            if(vis[idx] == 1)
                cnt--;
            vis[idx]--;
            left++;
            
            while(cnt < n and right < v.size()){
                int idx = v[right].second;
                if(vis[idx] == 0) 
                    cnt++;
                vis[idx]++;
                right++;
            }
            
            if(cnt == n){
                ans = min(ans, v[right-1].first - v[left].first);
            }
            else break;
        }
        return ans;
    }
};
