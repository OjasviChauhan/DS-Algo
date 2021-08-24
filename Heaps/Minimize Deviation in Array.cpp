// https://leetcode.com/problems/minimize-deviation-in-array/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);
        }
        while(minHeap.top() % 2 == 1) {
            int top = minHeap.top();
            minHeap.pop();
            top *= 2;
            minHeap.push(top);
        }
        
        int mn = minHeap.top();
        while(!minHeap.empty()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        int ans = maxHeap.top() - mn;
        while(maxHeap.top() % 2 == 0) {
            int top = maxHeap.top();
            maxHeap.pop();
            top /= 2;
            maxHeap.push(top);
            mn = min(mn, top);
            ans = min(ans, maxHeap.top() - mn);
        }
        return ans;
    }
};
