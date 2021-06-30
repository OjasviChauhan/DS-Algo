// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    // time: O(n)
    // space: O(k)
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        vector<int> ans;
        list<int> q;
        int start = 0, end = 0;
        
        for(end = 0; end < k; end++){
            while(!q.empty() and q.back() < A[end]) q.pop_back();
            q.push_back(A[end]);
        }
        ans.push_back(q.front());
        
        while(end < A.size()){
            if(A[start] == q.front()){
                q.pop_front();
            }
            start++;
            
            while(!q.empty() and q.back() < A[end]) q.pop_back();
            q.push_back(A[end]);
            end++;
            ans.push_back(q.front());
        }
        return ans;
    }
};
